
/**
  DAC2 Generated Driver File 

  @Company
    Microchip Technology Inc.

  @File Name
    dac2.c

  @Summary
    This is the generated driver implementation file for the DAC2 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides implementations for driver APIs for DAC2. 
    Generation Information : 
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.145.0
        Device            :  PIC24FJ64GC006
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36b
        MPLAB             :  MPLAB X v5.25
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

/**
  Section: Included Files
*/        
   
#include "dac2.h"

/**
  Section: Driver Interface
*/

void DAC2_Initialize(void)
{
    // DACREF AVDD; DACFM Right; DACEN enabled; DACTSEL CMP1; DACTRIG disabled; DACSLP disabled; DACSIDL disabled; 
    DAC2CON = 0x8002;
    
}

void DAC2_OutputSet(uint16_t inputData)
{
    DAC2DAT  = inputData;
}

void __attribute__ ((weak)) DAC2_CallBack(void)
{
    // Add your custom callback code here
}

void DAC2_Tasks ( void )
{
	if(IFS4bits.DAC2IF)
	{
		// DAC2 callback function 
		DAC2_CallBack();
		
		// clear the DAC2 interrupt flag
		IFS4bits.DAC2IF = 0;
	}
}
/**
  End of File
*/ 

