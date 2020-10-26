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
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.168.0
        Device            :  PIC24FJ64GC006
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB 	          :  MPLAB X v5.40
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
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

/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RB2, high using LATB2.

  @Description
    Sets the GPIO pin, RB2, high using LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB2 high (1)
    IO_RB2_SetHigh();
    </code>

*/
#define IO_RB2_SetHigh()          (_LATB2 = 1)
/**
  @Summary
    Sets the GPIO pin, RB2, low using LATB2.

  @Description
    Sets the GPIO pin, RB2, low using LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB2 low (0)
    IO_RB2_SetLow();
    </code>

*/
#define IO_RB2_SetLow()           (_LATB2 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB2, using LATB2.

  @Description
    Toggles the GPIO pin, RB2, using LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB2
    IO_RB2_Toggle();
    </code>

*/
#define IO_RB2_Toggle()           (_LATB2 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB2.

  @Description
    Reads the value of the GPIO pin, RB2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB2
    postValue = IO_RB2_GetValue();
    </code>

*/
#define IO_RB2_GetValue()         _RB2
/**
  @Summary
    Configures the GPIO pin, RB2, as an input.

  @Description
    Configures the GPIO pin, RB2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB2 as an input
    IO_RB2_SetDigitalInput();
    </code>

*/
#define IO_RB2_SetDigitalInput()  (_TRISB2 = 1)
/**
  @Summary
    Configures the GPIO pin, RB2, as an output.

  @Description
    Configures the GPIO pin, RB2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB2 as an output
    IO_RB2_SetDigitalOutput();
    </code>

*/
#define IO_RB2_SetDigitalOutput() (_TRISB2 = 0)
/**
  @Summary
    Sets the GPIO pin, RB3, high using LATB3.

  @Description
    Sets the GPIO pin, RB3, high using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB3 high (1)
    IO_RB3_SetHigh();
    </code>

*/
#define IO_RB3_SetHigh()          (_LATB3 = 1)
/**
  @Summary
    Sets the GPIO pin, RB3, low using LATB3.

  @Description
    Sets the GPIO pin, RB3, low using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB3 low (0)
    IO_RB3_SetLow();
    </code>

*/
#define IO_RB3_SetLow()           (_LATB3 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB3, using LATB3.

  @Description
    Toggles the GPIO pin, RB3, using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB3
    IO_RB3_Toggle();
    </code>

*/
#define IO_RB3_Toggle()           (_LATB3 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB3.

  @Description
    Reads the value of the GPIO pin, RB3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB3
    postValue = IO_RB3_GetValue();
    </code>

*/
#define IO_RB3_GetValue()         _RB3
/**
  @Summary
    Configures the GPIO pin, RB3, as an input.

  @Description
    Configures the GPIO pin, RB3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB3 as an input
    IO_RB3_SetDigitalInput();
    </code>

*/
#define IO_RB3_SetDigitalInput()  (_TRISB3 = 1)
/**
  @Summary
    Configures the GPIO pin, RB3, as an output.

  @Description
    Configures the GPIO pin, RB3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB3 as an output
    IO_RB3_SetDigitalOutput();
    </code>

*/
#define IO_RB3_SetDigitalOutput() (_TRISB3 = 0)
/**
  @Summary
    Sets the GPIO pin, RB4, high using LATB4.

  @Description
    Sets the GPIO pin, RB4, high using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB4 high (1)
    IO_RB4_SetHigh();
    </code>

*/
#define IO_RB4_SetHigh()          (_LATB4 = 1)
/**
  @Summary
    Sets the GPIO pin, RB4, low using LATB4.

  @Description
    Sets the GPIO pin, RB4, low using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB4 low (0)
    IO_RB4_SetLow();
    </code>

*/
#define IO_RB4_SetLow()           (_LATB4 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB4, using LATB4.

  @Description
    Toggles the GPIO pin, RB4, using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB4
    IO_RB4_Toggle();
    </code>

*/
#define IO_RB4_Toggle()           (_LATB4 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB4.

  @Description
    Reads the value of the GPIO pin, RB4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB4
    postValue = IO_RB4_GetValue();
    </code>

*/
#define IO_RB4_GetValue()         _RB4
/**
  @Summary
    Configures the GPIO pin, RB4, as an input.

  @Description
    Configures the GPIO pin, RB4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB4 as an input
    IO_RB4_SetDigitalInput();
    </code>

*/
#define IO_RB4_SetDigitalInput()  (_TRISB4 = 1)
/**
  @Summary
    Configures the GPIO pin, RB4, as an output.

  @Description
    Configures the GPIO pin, RB4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB4 as an output
    IO_RB4_SetDigitalOutput();
    </code>

*/
#define IO_RB4_SetDigitalOutput() (_TRISB4 = 0)
/**
  @Summary
    Sets the GPIO pin, RD1, high using LATD1.

  @Description
    Sets the GPIO pin, RD1, high using LATD1.

  @Preconditions
    The RD1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD1 high (1)
    SCK1OUT_SetHigh();
    </code>

*/
#define SCK1OUT_SetHigh()          (_LATD1 = 1)
/**
  @Summary
    Sets the GPIO pin, RD1, low using LATD1.

  @Description
    Sets the GPIO pin, RD1, low using LATD1.

  @Preconditions
    The RD1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD1 low (0)
    SCK1OUT_SetLow();
    </code>

*/
#define SCK1OUT_SetLow()           (_LATD1 = 0)
/**
  @Summary
    Toggles the GPIO pin, RD1, using LATD1.

  @Description
    Toggles the GPIO pin, RD1, using LATD1.

  @Preconditions
    The RD1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD1
    SCK1OUT_Toggle();
    </code>

*/
#define SCK1OUT_Toggle()           (_LATD1 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RD1.

  @Description
    Reads the value of the GPIO pin, RD1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD1
    postValue = SCK1OUT_GetValue();
    </code>

*/
#define SCK1OUT_GetValue()         _RD1
/**
  @Summary
    Configures the GPIO pin, RD1, as an input.

  @Description
    Configures the GPIO pin, RD1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD1 as an input
    SCK1OUT_SetDigitalInput();
    </code>

*/
#define SCK1OUT_SetDigitalInput()  (_TRISD1 = 1)
/**
  @Summary
    Configures the GPIO pin, RD1, as an output.

  @Description
    Configures the GPIO pin, RD1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD1 as an output
    SCK1OUT_SetDigitalOutput();
    </code>

*/
#define SCK1OUT_SetDigitalOutput() (_TRISD1 = 0)
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
    SDO1_SetHigh();
    </code>

*/
#define SDO1_SetHigh()          (_LATD2 = 1)
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
    SDO1_SetLow();
    </code>

*/
#define SDO1_SetLow()           (_LATD2 = 0)
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
    SDO1_Toggle();
    </code>

*/
#define SDO1_Toggle()           (_LATD2 ^= 1)
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
    postValue = SDO1_GetValue();
    </code>

*/
#define SDO1_GetValue()         _RD2
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
    SDO1_SetDigitalInput();
    </code>

*/
#define SDO1_SetDigitalInput()  (_TRISD2 = 1)
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
    SDO1_SetDigitalOutput();
    </code>

*/
#define SDO1_SetDigitalOutput() (_TRISD2 = 0)
/**
  @Summary
    Sets the GPIO pin, RD3, high using LATD3.

  @Description
    Sets the GPIO pin, RD3, high using LATD3.

  @Preconditions
    The RD3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD3 high (1)
    IO_RD3_SetHigh();
    </code>

*/
#define IO_RD3_SetHigh()          (_LATD3 = 1)
/**
  @Summary
    Sets the GPIO pin, RD3, low using LATD3.

  @Description
    Sets the GPIO pin, RD3, low using LATD3.

  @Preconditions
    The RD3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD3 low (0)
    IO_RD3_SetLow();
    </code>

*/
#define IO_RD3_SetLow()           (_LATD3 = 0)
/**
  @Summary
    Toggles the GPIO pin, RD3, using LATD3.

  @Description
    Toggles the GPIO pin, RD3, using LATD3.

  @Preconditions
    The RD3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD3
    IO_RD3_Toggle();
    </code>

*/
#define IO_RD3_Toggle()           (_LATD3 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RD3.

  @Description
    Reads the value of the GPIO pin, RD3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD3
    postValue = IO_RD3_GetValue();
    </code>

*/
#define IO_RD3_GetValue()         _RD3
/**
  @Summary
    Configures the GPIO pin, RD3, as an input.

  @Description
    Configures the GPIO pin, RD3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD3 as an input
    IO_RD3_SetDigitalInput();
    </code>

*/
#define IO_RD3_SetDigitalInput()  (_TRISD3 = 1)
/**
  @Summary
    Configures the GPIO pin, RD3, as an output.

  @Description
    Configures the GPIO pin, RD3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD3 as an output
    IO_RD3_SetDigitalOutput();
    </code>

*/
#define IO_RD3_SetDigitalOutput() (_TRISD3 = 0)
/**
  @Summary
    Sets the GPIO pin, RD4, high using LATD4.

  @Description
    Sets the GPIO pin, RD4, high using LATD4.

  @Preconditions
    The RD4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD4 high (1)
    IO_RD4_SetHigh();
    </code>

*/
#define IO_RD4_SetHigh()          (_LATD4 = 1)
/**
  @Summary
    Sets the GPIO pin, RD4, low using LATD4.

  @Description
    Sets the GPIO pin, RD4, low using LATD4.

  @Preconditions
    The RD4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD4 low (0)
    IO_RD4_SetLow();
    </code>

*/
#define IO_RD4_SetLow()           (_LATD4 = 0)
/**
  @Summary
    Toggles the GPIO pin, RD4, using LATD4.

  @Description
    Toggles the GPIO pin, RD4, using LATD4.

  @Preconditions
    The RD4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD4
    IO_RD4_Toggle();
    </code>

*/
#define IO_RD4_Toggle()           (_LATD4 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RD4.

  @Description
    Reads the value of the GPIO pin, RD4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD4
    postValue = IO_RD4_GetValue();
    </code>

*/
#define IO_RD4_GetValue()         _RD4
/**
  @Summary
    Configures the GPIO pin, RD4, as an input.

  @Description
    Configures the GPIO pin, RD4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD4 as an input
    IO_RD4_SetDigitalInput();
    </code>

*/
#define IO_RD4_SetDigitalInput()  (_TRISD4 = 1)
/**
  @Summary
    Configures the GPIO pin, RD4, as an output.

  @Description
    Configures the GPIO pin, RD4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD4 as an output
    IO_RD4_SetDigitalOutput();
    </code>

*/
#define IO_RD4_SetDigitalOutput() (_TRISD4 = 0)
/**
  @Summary
    Sets the GPIO pin, RE0, high using LATE0.

  @Description
    Sets the GPIO pin, RE0, high using LATE0.

  @Preconditions
    The RE0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE0 high (1)
    IO_RE0_SetHigh();
    </code>

*/
#define IO_RE0_SetHigh()          (_LATE0 = 1)
/**
  @Summary
    Sets the GPIO pin, RE0, low using LATE0.

  @Description
    Sets the GPIO pin, RE0, low using LATE0.

  @Preconditions
    The RE0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE0 low (0)
    IO_RE0_SetLow();
    </code>

*/
#define IO_RE0_SetLow()           (_LATE0 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE0, using LATE0.

  @Description
    Toggles the GPIO pin, RE0, using LATE0.

  @Preconditions
    The RE0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE0
    IO_RE0_Toggle();
    </code>

*/
#define IO_RE0_Toggle()           (_LATE0 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE0.

  @Description
    Reads the value of the GPIO pin, RE0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE0
    postValue = IO_RE0_GetValue();
    </code>

*/
#define IO_RE0_GetValue()         _RE0
/**
  @Summary
    Configures the GPIO pin, RE0, as an input.

  @Description
    Configures the GPIO pin, RE0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE0 as an input
    IO_RE0_SetDigitalInput();
    </code>

*/
#define IO_RE0_SetDigitalInput()  (_TRISE0 = 1)
/**
  @Summary
    Configures the GPIO pin, RE0, as an output.

  @Description
    Configures the GPIO pin, RE0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE0 as an output
    IO_RE0_SetDigitalOutput();
    </code>

*/
#define IO_RE0_SetDigitalOutput() (_TRISE0 = 0)
/**
  @Summary
    Sets the GPIO pin, RF0, high using LATF0.

  @Description
    Sets the GPIO pin, RF0, high using LATF0.

  @Preconditions
    The RF0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF0 high (1)
    IO_RF0_SetHigh();
    </code>

*/
#define IO_RF0_SetHigh()          (_LATF0 = 1)
/**
  @Summary
    Sets the GPIO pin, RF0, low using LATF0.

  @Description
    Sets the GPIO pin, RF0, low using LATF0.

  @Preconditions
    The RF0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF0 low (0)
    IO_RF0_SetLow();
    </code>

*/
#define IO_RF0_SetLow()           (_LATF0 = 0)
/**
  @Summary
    Toggles the GPIO pin, RF0, using LATF0.

  @Description
    Toggles the GPIO pin, RF0, using LATF0.

  @Preconditions
    The RF0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF0
    IO_RF0_Toggle();
    </code>

*/
#define IO_RF0_Toggle()           (_LATF0 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RF0.

  @Description
    Reads the value of the GPIO pin, RF0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF0
    postValue = IO_RF0_GetValue();
    </code>

*/
#define IO_RF0_GetValue()         _RF0
/**
  @Summary
    Configures the GPIO pin, RF0, as an input.

  @Description
    Configures the GPIO pin, RF0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF0 as an input
    IO_RF0_SetDigitalInput();
    </code>

*/
#define IO_RF0_SetDigitalInput()  (_TRISF0 = 1)
/**
  @Summary
    Configures the GPIO pin, RF0, as an output.

  @Description
    Configures the GPIO pin, RF0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF0 as an output
    IO_RF0_SetDigitalOutput();
    </code>

*/
#define IO_RF0_SetDigitalOutput() (_TRISF0 = 0)
/**
  @Summary
    Sets the GPIO pin, RF1, high using LATF1.

  @Description
    Sets the GPIO pin, RF1, high using LATF1.

  @Preconditions
    The RF1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF1 high (1)
    IO_RF1_SetHigh();
    </code>

*/
#define IO_RF1_SetHigh()          (_LATF1 = 1)
/**
  @Summary
    Sets the GPIO pin, RF1, low using LATF1.

  @Description
    Sets the GPIO pin, RF1, low using LATF1.

  @Preconditions
    The RF1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF1 low (0)
    IO_RF1_SetLow();
    </code>

*/
#define IO_RF1_SetLow()           (_LATF1 = 0)
/**
  @Summary
    Toggles the GPIO pin, RF1, using LATF1.

  @Description
    Toggles the GPIO pin, RF1, using LATF1.

  @Preconditions
    The RF1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF1
    IO_RF1_Toggle();
    </code>

*/
#define IO_RF1_Toggle()           (_LATF1 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RF1.

  @Description
    Reads the value of the GPIO pin, RF1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF1
    postValue = IO_RF1_GetValue();
    </code>

*/
#define IO_RF1_GetValue()         _RF1
/**
  @Summary
    Configures the GPIO pin, RF1, as an input.

  @Description
    Configures the GPIO pin, RF1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF1 as an input
    IO_RF1_SetDigitalInput();
    </code>

*/
#define IO_RF1_SetDigitalInput()  (_TRISF1 = 1)
/**
  @Summary
    Configures the GPIO pin, RF1, as an output.

  @Description
    Configures the GPIO pin, RF1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF1 as an output
    IO_RF1_SetDigitalOutput();
    </code>

*/
#define IO_RF1_SetDigitalOutput() (_TRISF1 = 0)
/**
  @Summary
    Sets the GPIO pin, RF4, high using LATF4.

  @Description
    Sets the GPIO pin, RF4, high using LATF4.

  @Preconditions
    The RF4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF4 high (1)
    channel_AN11_SetHigh();
    </code>

*/
#define channel_AN11_SetHigh()          (_LATF4 = 1)
/**
  @Summary
    Sets the GPIO pin, RF4, low using LATF4.

  @Description
    Sets the GPIO pin, RF4, low using LATF4.

  @Preconditions
    The RF4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF4 low (0)
    channel_AN11_SetLow();
    </code>

*/
#define channel_AN11_SetLow()           (_LATF4 = 0)
/**
  @Summary
    Toggles the GPIO pin, RF4, using LATF4.

  @Description
    Toggles the GPIO pin, RF4, using LATF4.

  @Preconditions
    The RF4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF4
    channel_AN11_Toggle();
    </code>

*/
#define channel_AN11_Toggle()           (_LATF4 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RF4.

  @Description
    Reads the value of the GPIO pin, RF4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF4
    postValue = channel_AN11_GetValue();
    </code>

*/
#define channel_AN11_GetValue()         _RF4
/**
  @Summary
    Configures the GPIO pin, RF4, as an input.

  @Description
    Configures the GPIO pin, RF4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF4 as an input
    channel_AN11_SetDigitalInput();
    </code>

*/
#define channel_AN11_SetDigitalInput()  (_TRISF4 = 1)
/**
  @Summary
    Configures the GPIO pin, RF4, as an output.

  @Description
    Configures the GPIO pin, RF4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF4 as an output
    channel_AN11_SetDigitalOutput();
    </code>

*/
#define channel_AN11_SetDigitalOutput() (_TRISF4 = 0)
/**
  @Summary
    Sets the GPIO pin, RG2, high using LATG2.

  @Description
    Sets the GPIO pin, RG2, high using LATG2.

  @Preconditions
    The RG2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG2 high (1)
    IO_RG2_SetHigh();
    </code>

*/
#define IO_RG2_SetHigh()          (_LATG2 = 1)
/**
  @Summary
    Sets the GPIO pin, RG2, low using LATG2.

  @Description
    Sets the GPIO pin, RG2, low using LATG2.

  @Preconditions
    The RG2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG2 low (0)
    IO_RG2_SetLow();
    </code>

*/
#define IO_RG2_SetLow()           (_LATG2 = 0)
/**
  @Summary
    Toggles the GPIO pin, RG2, using LATG2.

  @Description
    Toggles the GPIO pin, RG2, using LATG2.

  @Preconditions
    The RG2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG2
    IO_RG2_Toggle();
    </code>

*/
#define IO_RG2_Toggle()           (_LATG2 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RG2.

  @Description
    Reads the value of the GPIO pin, RG2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG2
    postValue = IO_RG2_GetValue();
    </code>

*/
#define IO_RG2_GetValue()         _RG2
/**
  @Summary
    Configures the GPIO pin, RG2, as an input.

  @Description
    Configures the GPIO pin, RG2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG2 as an input
    IO_RG2_SetDigitalInput();
    </code>

*/
#define IO_RG2_SetDigitalInput()  (_TRISG2 = 1)
/**
  @Summary
    Configures the GPIO pin, RG2, as an output.

  @Description
    Configures the GPIO pin, RG2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG2 as an output
    IO_RG2_SetDigitalOutput();
    </code>

*/
#define IO_RG2_SetDigitalOutput() (_TRISG2 = 0)
/**
  @Summary
    Sets the GPIO pin, RG3, high using LATG3.

  @Description
    Sets the GPIO pin, RG3, high using LATG3.

  @Preconditions
    The RG3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG3 high (1)
    IO_RG3_SetHigh();
    </code>

*/
#define IO_RG3_SetHigh()          (_LATG3 = 1)
/**
  @Summary
    Sets the GPIO pin, RG3, low using LATG3.

  @Description
    Sets the GPIO pin, RG3, low using LATG3.

  @Preconditions
    The RG3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG3 low (0)
    IO_RG3_SetLow();
    </code>

*/
#define IO_RG3_SetLow()           (_LATG3 = 0)
/**
  @Summary
    Toggles the GPIO pin, RG3, using LATG3.

  @Description
    Toggles the GPIO pin, RG3, using LATG3.

  @Preconditions
    The RG3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG3
    IO_RG3_Toggle();
    </code>

*/
#define IO_RG3_Toggle()           (_LATG3 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RG3.

  @Description
    Reads the value of the GPIO pin, RG3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG3
    postValue = IO_RG3_GetValue();
    </code>

*/
#define IO_RG3_GetValue()         _RG3
/**
  @Summary
    Configures the GPIO pin, RG3, as an input.

  @Description
    Configures the GPIO pin, RG3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG3 as an input
    IO_RG3_SetDigitalInput();
    </code>

*/
#define IO_RG3_SetDigitalInput()  (_TRISG3 = 1)
/**
  @Summary
    Configures the GPIO pin, RG3, as an output.

  @Description
    Configures the GPIO pin, RG3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG3 as an output
    IO_RG3_SetDigitalOutput();
    </code>

*/
#define IO_RG3_SetDigitalOutput() (_TRISG3 = 0)

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the PIC24FJ64GC006
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
