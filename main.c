/*****************************************************************************
  FileName:        main.c
  Processor:       PIC32MM0256GPM064
  Compiler:        XC32 ver 2.30
  IDE :            MPLABX-IDE 5.25
  Created by:      http://strefapic.blogspot.com
 ******************************************************************************/
/*----------------------------------------------------------------------------*/
/* Wiznet W5500 Ethernet Module connect                                       */
/*----------------------------------------------------------------------------*/
// ** Sample application for PIC32MM **
//    
//    W5500      --->    MCU PIC32MM
//     RST                     -->  RC14
//     MOSI                    -->  RA7 (MISO) 
//     MISO                    -->  RA8 (MOSI) 
//     SCK                     -->  RA10 
//     CS                      -->  RC11
//     INT                     -->  RD2  (not used))
/*----------------------------------------------------------------------------*/
/* UART for Printf() function                                                 */
/*----------------------------------------------------------------------------*/ 
//    Required connections for UART:
//    
//    CP210x Module     ---> MCU PIC32MM
//    TX                     --> RA6 (not used))
//    RX                     --> RC12 (TX)
/*----------------------------------------------------------------------------*/
/* LED                                                                        */
/*----------------------------------------------------------------------------*/ 
//    LED   -   RC13
//******************************************************************************
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/spi3.h"
#include "mcc_generated_files/pin_manager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "delay.h"
#include "wizchip_conf.h"
#include "w5500.h"
#include "socket.h"
#include "MQTTClient.h"


#define Wizchip_Reset PORTCbits.RC14

#define TCP_SOCKET        0     //socket W5500 for TCP connection
#define DATA_BUF_SIZE     2048  
#define targetPort        1883 // mqtt server/broker port
#define Token_Ubidots     "BBFF-dlkCOCzYMfLY9AV5wgxgsDrP2brXYZ" //Token Ubidots cloud


uint8_t targetIP[] = {169,55,61,243};   // mqtt server/broker IP
//uint16_t targetPort = 1883 ;          // mqtt server/broker port
uint8_t tempBuffer[DATA_BUF_SIZE] = {}; // Receive Buffer
uint8_t licznik = 1 ;
volatile uint16_t SoftTimer1 , SoftTimer2 ;

/*Call back function for W5500 SPI - Theses used as parametr of reg_wizchip_spi_cbfunc()
 Should be implemented by WIZCHIP users because host is dependent it*/
uint8_t CB_SpiRead(void);
void CB_ChipSelect(void);
void CB_ChipDeselect(void);
void CB_SpiWrite(uint8_t wb);
void messageArrived(MessageData* md);
void PublishTopic(void);
void SubscribeTopic(void);

void W5500_Init(void);
void network_init(void);

/*definition of network parameters for W5500*/
 wiz_NetInfo gWIZNETINFO =
{
  .mac = {0xba, 0x5a, 0x4d, 0xb4, 0xc3, 0xe0},   // Source Mac Address 
  .ip = {192, 168,  8, 220},                     // Source IP Address
  .sn = {255, 255, 255, 0},                      // Subnet Mask
  .gw = {192, 168,  8, 1},                       // Gateway IP Address
  .dns = {192, 168, 8, 1},                       // DNS server IP Address
  .dhcp = NETINFO_STATIC
 
 };
/*MQTT structur*/
 struct opts_struct
{
	char* clientid;
	int nodelimiter;
	char* delimiter;
	enum QoS qos;
	char* username;
	char* password;
	char* host;
	int port;
	int showtopics;
} opts ={ (char*)"stdout-subscriber", 0, (char*)"\n", QOS0, (char*)Token_Ubidots, (char*)Token_Ubidots, targetIP, targetPort, 1 };  

Network n;
MQTTClient c;
 
int main(void)
{
    int8_t rc = 0;
    uint8_t buf[1024]; //watch out for this buffer, here must fit the Tokens and everything we send
    // initialize the device
    SYSTEM_Initialize();
    printf("\r\n***** W5500_TEST_START *****\r\n");
    W5500_Init();
    printf("\r\n***** W5500 successfully connect to Router *****\r\n"); // must be connect cable W5500 to Router
    
    TMR1_Start(); //TMR1 tick 1ms for libs MQTT
    START :   //required for reconnect process
    /*open socket and connect broker MQTT*/
    while(!ConnectNetwork(&n, targetIP, targetPort));// socket open and connect ,sucess mast be
    
    NewNetwork(&n, TCP_SOCKET);
    
    MQTTClientInit(&c,&n,1000,buf,sizeof(buf),tempBuffer,2048);
    
    MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
	data.willFlag = 0;
	data.MQTTVersion = 3;
	data.clientID.cstring = opts.clientid;
	data.username.cstring = opts.username;
	data.password.cstring = opts.password;

	data.keepAliveInterval = 60;
	data.cleansession = 1;
    /*MQTT Connect - send an MQTT connect packet down the network and wait for a Connack*/
    rc = MQTTConnect(&c, &data);
    
    SubscribeTopic();
            
    while (1)
    {
        MQTTYield(&c, data.keepAliveInterval) ; // read the socket, see what work is due 
        /*Publish Topic*/
        if(!SoftTimer1) {
           SoftTimer1 = 3000 ; /*TMR1 x SoftTimer1 = 1ms x 3000 = 3000 ms*/
           PublishTopic();  //publish topic every 3 seconds  
        }
        /*Get Status Socket Connect*/
        if(!SoftTimer2) {
           SoftTimer2 = 10000 ; /*TMR1 x SoftTimer2 = 1ms x 10000 = 10 s*/
           if(getSn_SR(TCP_SOCKET) == SOCK_CLOSED){
             printf("\r\n***** RECONNECT !!! *****\r\n"); 
             goto START ;
           }
        }
           
    }
    
}


/*Call back function for W5500 SPI*/

void CB_ChipSelect(void) // Call back function for WIZCHIP select.
{
    CS_SetLow();
}

void CB_ChipDeselect(void) // Call back function for WIZCHIP deselect.
{
    CS_SetHigh();
}

uint8_t CB_SpiRead(void) // Callback function to read byte usig SPI.
{
    return SPI3_Exchange8bit(0xFF);
}

void CB_SpiWrite(uint8_t wb) // Callback function to write byte usig SPI.
{
    SPI3_Exchange8bit(wb);
    
}


/* Initialize modules */
 void W5500_Init(void)
{
    // Set Tx and Rx buffer size to 2KB
    uint8_t txsize[8] = {2,2,2,2,2,2,2,2};
    uint8_t rxsize[8] = {2,2,2,2,2,2,2,2};
    uint8_t tmp;  
    CB_ChipDeselect();  // Deselect module

    // Reset module
    Wizchip_Reset = 0;
    delayMs(1);
    Wizchip_Reset = 1;
    delayMs(1);

     /* Registration call back */
     //_WIZCHIP_IO_MODE_ = _WIZCHIP_IO_MODE_SPI_VDM_
    reg_wizchip_cs_cbfunc(CB_ChipSelect, CB_ChipDeselect);

    /* SPI Read & Write callback function */
    reg_wizchip_spi_cbfunc(CB_SpiRead, CB_SpiWrite);
     
    /* WIZCHIP SOCKET Buffer initialize */
       wizchip_init(txsize,rxsize);
    
    /* PHY link status check */
    do
    {
       if(!(ctlwizchip(CW_GET_PHYLINK, (void*)&tmp)))
          printf("\r\nUnknown PHY Link status.\r\n");
       delayMs(500);
    }  while(tmp == PHY_LINK_OFF); 
    printf("\r\nPHY Link status OK.\r\n");
    
    /*Intialize the network information to be used in WIZCHIP*/
    network_init();
}

void network_init(void)
{
  uint8_t tmpstr[6];
  wiz_NetInfo pnetinfo; //for Read registers value
  ctlnetwork(CN_SET_NETINFO, (void*)&gWIZNETINFO); // Write Network Settings to W5500 registers
  // Display Network Information 
  ctlnetwork(CN_GET_NETINFO, (void*)&pnetinfo);    // Read registers value , W5500 Network Settings    
  ctlwizchip(CW_GET_ID,(void*)tmpstr); //GET ID WIZNET like this : W5500
  /*Send the data to the Uart*/
  printf("\r\n=== %s NET CONF ===\r\n",(char*)tmpstr);
  printf("\r\nMAC: %02X:%02X:%02X:%02X:%02X:%02X\r\n", pnetinfo.mac[0],pnetinfo.mac[1],pnetinfo.mac[2],
		   pnetinfo.mac[3],pnetinfo.mac[4],pnetinfo.mac[5]);
  printf("SIP: %d.%d.%d.%d\r\n", pnetinfo.ip[0],pnetinfo.ip[1],pnetinfo.ip[2],pnetinfo.ip[3]);
  printf("GAR: %d.%d.%d.%d\r\n", pnetinfo.gw[0],pnetinfo.gw[1],pnetinfo.gw[2],pnetinfo.gw[3]);
  printf("SUB: %d.%d.%d.%d\r\n", pnetinfo.sn[0],pnetinfo.sn[1],pnetinfo.sn[2],pnetinfo.sn[3]);
  printf("DNS: %d.%d.%d.%d\r\n", pnetinfo.dns[0],pnetinfo.dns[1],pnetinfo.dns[2],pnetinfo.dns[3]);
  printf("======================\r\n");

}

// MQTT messageArrived callback function
void messageArrived(MessageData* md)
{
	uint8_t messageBuffer[100];
    	
    MQTTMessage* message = md->message;
    
	if (opts.showtopics)
	{
		memcpy(messageBuffer,(char*)message->payload,(int)message->payloadlen);
		                		
	}

	if (opts.nodelimiter)
        printf("\r\n%.*s\r\n", (int)message->payloadlen, (char*)message->payload);
    
	else 
        printf("\r\n%.*s%s\r\n", (int)message->payloadlen, (char*)message->payload, opts.delimiter);
      
    if(messageBuffer[0] == '0') LED_SetLow();
    if(messageBuffer[0] == '1') LED_SetHigh();
        
}
 
void PublishTopic(void){
    
    uint8_t dataPublish[256] ;
    int8_t rc ;
    /*Publish Topic Object*/
    MQTTMessage message_temperaturasalon ;
       
    sprintf(dataPublish,"{\"temperaturasalon\": %d}", licznik);
    
    message_temperaturasalon.payload = (char*)dataPublish;
    message_temperaturasalon.payloadlen = strlen(dataPublish);
    message_temperaturasalon.qos = 0;
    message_temperaturasalon.retained = 0;
    message_temperaturasalon.dup = 0;
    
    rc = MQTTPublish(&c, "/v1.6/devices/pic32", &message_temperaturasalon);
    if(rc == 0) printf("Published Sucess: %s\r\n",dataPublish); //rc = 0 (Sucess) / -1 (FAILURE)) 
      else printf("Published Failure\r\n"); //rc = 0 (Sucess) / -1 (FAILURE))
    licznik++ ;
    if(licznik > 10) licznik = 1;
     
}

void SubscribeTopic(void){
    int8_t rc ;
    rc = MQTTSubscribe(&c, "/v1.6/devices/pic32/switch/lv", opts.qos, messageArrived);
	if(rc == 0) {
        printf("\r\nSubscribed Sucess: "); //rc = 0 (Sucess)
        printf("/v1.6/devices/pic32/switch/lv\r\n");
    }
    else printf("\r\nSubscribed Error\r\n"); //rc = -1 (Error) 
}

