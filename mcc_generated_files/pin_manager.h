/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.145.0
        Device            :  PIC32MM0256GPM064
    The generated drivers are tested against the following:
        Compiler          :  XC32 v2.20
        MPLAB 	          :  MPLAB X v5.25
*/

/*
    (c) 2019 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>
#include <stdbool.h>
/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RA10, high using LATA10.

  @Description
    Sets the GPIO pin, RA10, high using LATA10.

  @Preconditions
    The RA10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA10 high (1)
    SCK3_SetHigh();
    </code>

*/
#define SCK3_SetHigh()          ( LATASET = (1 << 10) )
/**
  @Summary
    Sets the GPIO pin, RA10, low using LATA10.

  @Description
    Sets the GPIO pin, RA10, low using LATA10.

  @Preconditions
    The RA10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA10 low (0)
    SCK3_SetLow();
    </code>

*/
#define SCK3_SetLow()           ( LATACLR = (1 << 10) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RA10, low or high using LATA10.

  @Preconditions
    The RA10 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RA10 to low.
    SCK3_SetValue(false);
    </code>

*/
inline static void SCK3_SetValue(bool value)
{
  if(value)
  {
    SCK3_SetHigh();
  }
  else
  {
    SCK3_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RA10, using LATA10.

  @Description
    Toggles the GPIO pin, RA10, using LATA10.

  @Preconditions
    The RA10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA10
    SCK3_Toggle();
    </code>

*/
#define SCK3_Toggle()           ( LATAINV = (1 << 10) )
/**
  @Summary
    Reads the value of the GPIO pin, RA10.

  @Description
    Reads the value of the GPIO pin, RA10.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA10
    postValue = SCK3_GetValue();
    </code>

*/
#define SCK3_GetValue()         PORTAbits.RA10
/**
  @Summary
    Configures the GPIO pin, RA10, as an input.

  @Description
    Configures the GPIO pin, RA10, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA10 as an input
    SCK3_SetDigitalInput();
    </code>

*/
#define SCK3_SetDigitalInput()   ( TRISASET = (1 << 10) )
/**
  @Summary
    Configures the GPIO pin, RA10, as an output.

  @Description
    Configures the GPIO pin, RA10, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA10 as an output
    SCK3_SetDigitalOutput();
    </code>

*/
#define SCK3_SetDigitalOutput()   ( TRISACLR = (1 << 10) )
/**
  @Summary
    Sets the GPIO pin, RA7, high using LATA7.

  @Description
    Sets the GPIO pin, RA7, high using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA7 high (1)
    MISO3_SetHigh();
    </code>

*/
#define MISO3_SetHigh()          ( LATASET = (1 << 7) )
/**
  @Summary
    Sets the GPIO pin, RA7, low using LATA7.

  @Description
    Sets the GPIO pin, RA7, low using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA7 low (0)
    MISO3_SetLow();
    </code>

*/
#define MISO3_SetLow()           ( LATACLR = (1 << 7) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RA7, low or high using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RA7 to low.
    MISO3_SetValue(false);
    </code>

*/
inline static void MISO3_SetValue(bool value)
{
  if(value)
  {
    MISO3_SetHigh();
  }
  else
  {
    MISO3_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RA7, using LATA7.

  @Description
    Toggles the GPIO pin, RA7, using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA7
    MISO3_Toggle();
    </code>

*/
#define MISO3_Toggle()           ( LATAINV = (1 << 7) )
/**
  @Summary
    Reads the value of the GPIO pin, RA7.

  @Description
    Reads the value of the GPIO pin, RA7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA7
    postValue = MISO3_GetValue();
    </code>

*/
#define MISO3_GetValue()         PORTAbits.RA7
/**
  @Summary
    Configures the GPIO pin, RA7, as an input.

  @Description
    Configures the GPIO pin, RA7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA7 as an input
    MISO3_SetDigitalInput();
    </code>

*/
#define MISO3_SetDigitalInput()   ( TRISASET = (1 << 7) )
/**
  @Summary
    Configures the GPIO pin, RA7, as an output.

  @Description
    Configures the GPIO pin, RA7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA7 as an output
    MISO3_SetDigitalOutput();
    </code>

*/
#define MISO3_SetDigitalOutput()   ( TRISACLR = (1 << 7) )
/**
  @Summary
    Sets the GPIO pin, RA8, high using LATA8.

  @Description
    Sets the GPIO pin, RA8, high using LATA8.

  @Preconditions
    The RA8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA8 high (1)
    MOSI3_SetHigh();
    </code>

*/
#define MOSI3_SetHigh()          ( LATASET = (1 << 8) )
/**
  @Summary
    Sets the GPIO pin, RA8, low using LATA8.

  @Description
    Sets the GPIO pin, RA8, low using LATA8.

  @Preconditions
    The RA8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA8 low (0)
    MOSI3_SetLow();
    </code>

*/
#define MOSI3_SetLow()           ( LATACLR = (1 << 8) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RA8, low or high using LATA8.

  @Preconditions
    The RA8 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RA8 to low.
    MOSI3_SetValue(false);
    </code>

*/
inline static void MOSI3_SetValue(bool value)
{
  if(value)
  {
    MOSI3_SetHigh();
  }
  else
  {
    MOSI3_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RA8, using LATA8.

  @Description
    Toggles the GPIO pin, RA8, using LATA8.

  @Preconditions
    The RA8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA8
    MOSI3_Toggle();
    </code>

*/
#define MOSI3_Toggle()           ( LATAINV = (1 << 8) )
/**
  @Summary
    Reads the value of the GPIO pin, RA8.

  @Description
    Reads the value of the GPIO pin, RA8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA8
    postValue = MOSI3_GetValue();
    </code>

*/
#define MOSI3_GetValue()         PORTAbits.RA8
/**
  @Summary
    Configures the GPIO pin, RA8, as an input.

  @Description
    Configures the GPIO pin, RA8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA8 as an input
    MOSI3_SetDigitalInput();
    </code>

*/
#define MOSI3_SetDigitalInput()   ( TRISASET = (1 << 8) )
/**
  @Summary
    Configures the GPIO pin, RA8, as an output.

  @Description
    Configures the GPIO pin, RA8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA8 as an output
    MOSI3_SetDigitalOutput();
    </code>

*/
#define MOSI3_SetDigitalOutput()   ( TRISACLR = (1 << 8) )
/**
  @Summary
    Sets the GPIO pin, RC11, high using LATC11.

  @Description
    Sets the GPIO pin, RC11, high using LATC11.

  @Preconditions
    The RC11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC11 high (1)
    CS_SetHigh();
    </code>

*/
#define CS_SetHigh()          ( LATCSET = (1 << 11) )
/**
  @Summary
    Sets the GPIO pin, RC11, low using LATC11.

  @Description
    Sets the GPIO pin, RC11, low using LATC11.

  @Preconditions
    The RC11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC11 low (0)
    CS_SetLow();
    </code>

*/
#define CS_SetLow()           ( LATCCLR = (1 << 11) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RC11, low or high using LATC11.

  @Preconditions
    The RC11 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RC11 to low.
    CS_SetValue(false);
    </code>

*/
inline static void CS_SetValue(bool value)
{
  if(value)
  {
    CS_SetHigh();
  }
  else
  {
    CS_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RC11, using LATC11.

  @Description
    Toggles the GPIO pin, RC11, using LATC11.

  @Preconditions
    The RC11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC11
    CS_Toggle();
    </code>

*/
#define CS_Toggle()           ( LATCINV = (1 << 11) )
/**
  @Summary
    Reads the value of the GPIO pin, RC11.

  @Description
    Reads the value of the GPIO pin, RC11.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC11
    postValue = CS_GetValue();
    </code>

*/
#define CS_GetValue()         PORTCbits.RC11
/**
  @Summary
    Configures the GPIO pin, RC11, as an input.

  @Description
    Configures the GPIO pin, RC11, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC11 as an input
    CS_SetDigitalInput();
    </code>

*/
#define CS_SetDigitalInput()   ( TRISCSET = (1 << 11) )
/**
  @Summary
    Configures the GPIO pin, RC11, as an output.

  @Description
    Configures the GPIO pin, RC11, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC11 as an output
    CS_SetDigitalOutput();
    </code>

*/
#define CS_SetDigitalOutput()   ( TRISCCLR = (1 << 11) )
/**
  @Summary
    Sets the GPIO pin, RC13, high using LATC13.

  @Description
    Sets the GPIO pin, RC13, high using LATC13.

  @Preconditions
    The RC13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC13 high (1)
    LED_SetHigh();
    </code>

*/
#define LED_SetHigh()          ( LATCSET = (1 << 13) )
/**
  @Summary
    Sets the GPIO pin, RC13, low using LATC13.

  @Description
    Sets the GPIO pin, RC13, low using LATC13.

  @Preconditions
    The RC13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC13 low (0)
    LED_SetLow();
    </code>

*/
#define LED_SetLow()           ( LATCCLR = (1 << 13) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RC13, low or high using LATC13.

  @Preconditions
    The RC13 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RC13 to low.
    LED_SetValue(false);
    </code>

*/
inline static void LED_SetValue(bool value)
{
  if(value)
  {
    LED_SetHigh();
  }
  else
  {
    LED_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RC13, using LATC13.

  @Description
    Toggles the GPIO pin, RC13, using LATC13.

  @Preconditions
    The RC13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC13
    LED_Toggle();
    </code>

*/
#define LED_Toggle()           ( LATCINV = (1 << 13) )
/**
  @Summary
    Reads the value of the GPIO pin, RC13.

  @Description
    Reads the value of the GPIO pin, RC13.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC13
    postValue = LED_GetValue();
    </code>

*/
#define LED_GetValue()         PORTCbits.RC13
/**
  @Summary
    Configures the GPIO pin, RC13, as an input.

  @Description
    Configures the GPIO pin, RC13, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC13 as an input
    LED_SetDigitalInput();
    </code>

*/
#define LED_SetDigitalInput()   ( TRISCSET = (1 << 13) )
/**
  @Summary
    Configures the GPIO pin, RC13, as an output.

  @Description
    Configures the GPIO pin, RC13, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC13 as an output
    LED_SetDigitalOutput();
    </code>

*/
#define LED_SetDigitalOutput()   ( TRISCCLR = (1 << 13) )
/**
  @Summary
    Sets the GPIO pin, RC14, high using LATC14.

  @Description
    Sets the GPIO pin, RC14, high using LATC14.

  @Preconditions
    The RC14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC14 high (1)
    RESET_SetHigh();
    </code>

*/
#define RESET_SetHigh()          ( LATCSET = (1 << 14) )
/**
  @Summary
    Sets the GPIO pin, RC14, low using LATC14.

  @Description
    Sets the GPIO pin, RC14, low using LATC14.

  @Preconditions
    The RC14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC14 low (0)
    RESET_SetLow();
    </code>

*/
#define RESET_SetLow()           ( LATCCLR = (1 << 14) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RC14, low or high using LATC14.

  @Preconditions
    The RC14 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RC14 to low.
    RESET_SetValue(false);
    </code>

*/
inline static void RESET_SetValue(bool value)
{
  if(value)
  {
    RESET_SetHigh();
  }
  else
  {
    RESET_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RC14, using LATC14.

  @Description
    Toggles the GPIO pin, RC14, using LATC14.

  @Preconditions
    The RC14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC14
    RESET_Toggle();
    </code>

*/
#define RESET_Toggle()           ( LATCINV = (1 << 14) )
/**
  @Summary
    Reads the value of the GPIO pin, RC14.

  @Description
    Reads the value of the GPIO pin, RC14.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC14
    postValue = RESET_GetValue();
    </code>

*/
#define RESET_GetValue()         PORTCbits.RC14
/**
  @Summary
    Configures the GPIO pin, RC14, as an input.

  @Description
    Configures the GPIO pin, RC14, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC14 as an input
    RESET_SetDigitalInput();
    </code>

*/
#define RESET_SetDigitalInput()   ( TRISCSET = (1 << 14) )
/**
  @Summary
    Configures the GPIO pin, RC14, as an output.

  @Description
    Configures the GPIO pin, RC14, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC14 as an output
    RESET_SetDigitalOutput();
    </code>

*/
#define RESET_SetDigitalOutput()   ( TRISCCLR = (1 << 14) )
/**
  @Summary
    Sets the GPIO pin, RD2, high using LATD2.

  @Description
    Sets the GPIO pin, RD2, high using LATD2.

  @Preconditions
    The RD2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD2 high (1)
    INT_W5500_SetHigh();
    </code>

*/
#define INT_W5500_SetHigh()          ( LATDSET = (1 << 2) )
/**
  @Summary
    Sets the GPIO pin, RD2, low using LATD2.

  @Description
    Sets the GPIO pin, RD2, low using LATD2.

  @Preconditions
    The RD2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD2 low (0)
    INT_W5500_SetLow();
    </code>

*/
#define INT_W5500_SetLow()           ( LATDCLR = (1 << 2) )

/**
  @Summary
    Sets a value to the GPIO pin.

  @Description
    Sets or Resets the GPIO pin, RD2, low or high using LATD2.

  @Preconditions
    The RD2 must be set to an output.

  @Returns
    None.

  @Param
    bool value; : value to be set to the GPIO pin.

  @Example
    <code>
    // Set RD2 to low.
    INT_W5500_SetValue(false);
    </code>

*/
inline static void INT_W5500_SetValue(bool value)
{
  if(value)
  {
    INT_W5500_SetHigh();
  }
  else
  {
    INT_W5500_SetLow();
  }
}

/**
  @Summary
    Toggles the GPIO pin, RD2, using LATD2.

  @Description
    Toggles the GPIO pin, RD2, using LATD2.

  @Preconditions
    The RD2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD2
    INT_W5500_Toggle();
    </code>

*/
#define INT_W5500_Toggle()           ( LATDINV = (1 << 2) )
/**
  @Summary
    Reads the value of the GPIO pin, RD2.

  @Description
    Reads the value of the GPIO pin, RD2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD2
    postValue = INT_W5500_GetValue();
    </code>

*/
#define INT_W5500_GetValue()         PORTDbits.RD2
/**
  @Summary
    Configures the GPIO pin, RD2, as an input.

  @Description
    Configures the GPIO pin, RD2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD2 as an input
    INT_W5500_SetDigitalInput();
    </code>

*/
#define INT_W5500_SetDigitalInput()   ( TRISDSET = (1 << 2) )
/**
  @Summary
    Configures the GPIO pin, RD2, as an output.

  @Description
    Configures the GPIO pin, RD2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD2 as an output
    INT_W5500_SetDigitalOutput();
    </code>

*/
#define INT_W5500_SetDigitalOutput()   ( TRISDCLR = (1 << 2) )

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the PIC32MM0256GPM064
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize (void);

#endif
