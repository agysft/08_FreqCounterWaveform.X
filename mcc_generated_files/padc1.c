/*******************************************************************************
  PADC1 Generated Driver File

  Company:
    Microchip Technology Inc.

  File Name:
    padc1.c

  Summary:
    This is the generated driver implementation file for the PADC1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  Description:
    This source file provides implementations for driver APIs for PADC1.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.168.0
        Device            :  PIC24FJ64GC006
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB             :  MPLAB X v5.40
*******************************************************************************/

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

#include "padc1.h"

/**
  Prototype:        void PADC1_Initialize(void)
  Input:            none
  Output:           none
  Description:      PADC1_Initialize is an
                    initialization routine that takes inputs from the GUI.
  Comment:          
  Usage:            PADC1_Initialize();
*/
void PADC1_Initialize(void)
{
    // ADSLP disabled; ADSIDL disabled; PWRLVL Low-Power mode; PUMPEN disabled; FORM Integer, Raw Data; ADCAL disabled; ADON enabled; 
    ADCON1 = (0x8000 | 0x01) & 0x7FFF; //Full power mode, Enable ADC later

    // NVCFG0 AVSS; PVCFG AVDD; REFPUMP disabled; BUFORG disabled; 
    ADCON2 = (0x00 | 0x0300);
    ADCON2bits.BUFORG = 1;  // Result buffer organized as indexed mode

    // BUFOE disabled; BUFSTBY Normal; BUFEN disabled; BUFSIDL disabled; BUFSLP disabled; BUFREF 1.2 V; 
    BUFCON1 = 0x00;   

    // SLEN3 disabled; SLEN2 disabled; SLEN1 disabled; ADRC FOSC/2; SLEN0 disabled; ADCS 2; 
    ADCON3 = 0x01;
        
    //Set Sample lists

    // MULCHEN One at a time; CTMEN disabled; CM Matching is disabled; SLINT No interrupt; WM All conversion results saved; SAMC 0 tad; ASEN disabled; 
    ADL0CONH = 0x00;
    ADL0CONHbits.SLINT = 0x02; //Interrupt after all entries in a sample list have been converted
    // THSRC Buffer register; SLTSRC TMR2; SLEN enabled; SLENCLR disabled; SLSIZE 1; SAMP disabled; 
    ADL0CONL = (0x8500 & 0x7FFF) | 0x4000;  // open manual switch and Enable sample list later
    
    //Set table registers
    // UCTMU disabled; ADCH AN11; DIFF disabled; 
    ADTBL0 =  0xb;

    // Set table pointer registers
    ADL0PTR =0;
    ADL1PTR =0;
    ADL2PTR =0;
    ADL3PTR =0;

    // TBLSEL ADTBL0; COUNT 0; 
    ACCONL = 0x00;
    // ACIE disabled; ACEN disabled; 
    ACCONH = 0x00; 

    
    //Enable ADC
    ADCON1bits.ADON = 1; 
        
    //Poll the ADREADY bit
    while(!(PADC1_IsReadyForConversion()));
    
    // Start calibration   
    ADCON1bits.ADCAL = 1; 
        
    //Poll the ADREADY bit
    while(!(PADC1_IsReadyForConversion()));

    //Set ADC timer register
    // ADTMRPR 0; 
    ADTMRPR = 0x00;

   //Enable sample list

    ADL0CONLbits.SLEN = 1; // Enable Sample list 1
    ADL0CONLbits.SAMP = 0; // Close sample switch
}

bool PADC1_IsReadyForConversion(void)
{
    return(ADSTATHbits.ADREADY);
}

bool PADC1_IsBusyInConversion(void)
{
    return(ADSTATHbits.ADBUSY);
}

void PADC1_SampleList0ManualConversionStart(void)
{
    ADL0CONLbits.SAMP = 1;
    ADL0CONLbits.SAMP = 0;
}

void PADC1_SampleList1ManualConversionStart(void)
{
    ADL1CONLbits.SAMP = 1;
    ADL1CONLbits.SAMP = 0;
}

void PADC1_SampleList2ManualConversionStart(void)
{
    ADL2CONLbits.SAMP = 1;
    ADL2CONLbits.SAMP = 0;
}

void PADC1_SampleList3ManualConversionStart(void)
{
    ADL3CONLbits.SAMP = 1;
    ADL3CONLbits.SAMP = 0;
}

void PADC1_SampleList0Setup(PADC1_SAMPLELISTCONFIG *samplelistconfig)
{
    //threshold compare,CTMU ,Multichannel disabled
   ADL0CONHbits.ASEN = samplelistconfig->autoscan; //sequential scan
   ADL0CONHbits.SLINT = samplelistconfig->autoscan; //auto or sequential scan;
   ADL0CONHbits.SAMC = samplelistconfig->chargetime;
   ADL0CONHbits.WM = 0;
   ADL0CONLbits.SLTSRC = samplelistconfig->trigger_src;
   ADL0CONLbits.SLSIZE = (samplelistconfig->slsize -1);
   ADL0PTR = 0;
   //enable sample list
   ADL0CONLbits.SLEN = 1; 
}

void PADC1_SampleList1Setup(PADC1_SAMPLELISTCONFIG *samplelistconfig)
{
    //threshold compare,CTMU ,Multichannel disabled
   ADL1CONHbits.ASEN = samplelistconfig->autoscan; //auto or sequential scan
   ADL1CONHbits.SLINT = (samplelistconfig->autoscan)?1:2;
   ADL1CONHbits.SAMC = samplelistconfig->chargetime;
   ADL1CONHbits.WM = 0;
   ADL1CONLbits.SLTSRC = samplelistconfig->trigger_src;
   ADL1CONLbits.SLSIZE = (samplelistconfig->slsize -1);
   ADL1PTR = 0;
   //enable sample list
   ADL1CONLbits.SLEN = 1;
}

void PADC1_SampleList2Setup(PADC1_SAMPLELISTCONFIG *samplelistconfig)
{
     //threshold compare,CTMU ,Multichannel disabled
   ADL2CONHbits.ASEN = samplelistconfig->autoscan; //auto or sequential scan
   ADL2CONHbits.SLINT = (samplelistconfig->autoscan)?1:2;
   ADL2CONHbits.SAMC = samplelistconfig->chargetime;
   ADL2CONHbits.WM = 0;
   ADL2CONLbits.SLTSRC = samplelistconfig->trigger_src;
   ADL2CONLbits.SLSIZE = (samplelistconfig->slsize -1);
   ADL2PTR = 0;
   //enable sample list
   ADL2CONLbits.SLEN = 1;
}

void PADC1_SampleList3Setup(PADC1_SAMPLELISTCONFIG *samplelistconfig)
{
    //threshold compare,CTMU ,Multichannel disabled
   ADL3CONHbits.ASEN = samplelistconfig->autoscan; //auto or sequential scan
   ADL3CONHbits.SLINT = 1;
   ADL3CONHbits.SAMC = samplelistconfig->chargetime;
   ADL3CONHbits.WM = 0;
   ADL3CONLbits.SLTSRC = samplelistconfig->trigger_src;
   ADL3CONLbits.SLSIZE = (samplelistconfig->slsize -1);
   ADL3PTR = 0;
   //enable sample list
   ADL3CONLbits.SLEN = 1;
}

void PADC1_SampleList0Disable(void)
{
    ADL0CONLbits.SLEN = 0;
}

void PADC1_SampleList1Disable(void)
{
    ADL1CONLbits.SLEN = 0;
}

void PADC1_SampleList2Disable(void)
{
    ADL2CONLbits.SLEN = 0;
}

void PADC1_SampleList3Disable(void)
{
    ADL3CONLbits.SLEN = 0;
}        

void PADC1_SetADCChannel( uint8_t tableRegIndex, uint8_t adcChannel, bool diffEnable )
{
    uint16_t *tablereg;
    tablereg = (uint16_t *)&ADTBL0 + tableRegIndex;
    *tablereg = adcChannel + (diffEnable << 14);
}

bool PADC1_SampleList0ConversionResultBufferGet(uint16_t *buffer, uint8_t tableRegIndex, uint8_t slSize)
{
    uint8_t index;
    bool dataValid = false;
    if(ADSTATLbits.SL0IF != 0)
    {
        for(index=0;index<slSize;index++)
        {
           buffer[index] = *((uint16_t *)&ADRES0 + tableRegIndex);
           tableRegIndex++;
        }
        ADL0STATbits.ADLIF = 0;
        dataValid = true;
    }
    return dataValid;
}

bool PADC1_SampleList1ConversionResultBufferGet(uint16_t *buffer, uint8_t tableRegIndex, uint8_t slSize)
{
    uint8_t index;
    bool dataValid = false;
    if(ADSTATLbits.SL1IF != 0)
    {
        for(index=0;index<slSize;index++)
        {
           buffer[index] = *((uint16_t *)&ADRES0 + tableRegIndex);
           tableRegIndex++;
        }
        ADL1STATbits.ADLIF = 0;
        dataValid = true;
    }
    return dataValid;
}

bool PADC1_SampleList2ConversionResultBufferGet(uint16_t *buffer, uint8_t tableRegIndex, uint8_t slSize)
{
    uint8_t index;
    bool dataValid = false;
    if(ADSTATLbits.SL2IF != 0)
    {
        for(index=0;index<slSize;index++)
        {
           buffer[index] = *((uint16_t *)&ADRES0 + tableRegIndex);
           tableRegIndex++;
        }
        ADL2STATbits.ADLIF = 0;
        dataValid = true;
    }
    return dataValid;
}

bool PADC1_SampleList3ConversionResultBufferGet(uint16_t *buffer, uint8_t tableRegIndex, uint8_t slSize)
{
    uint8_t index;
    bool dataValid = false;
    if(ADSTATLbits.SL3IF != 0)
    {
        for(index=0;index<slSize;index++)
        {
           buffer[index] = *((uint16_t *)&ADRES0 + tableRegIndex);
           tableRegIndex++;
        }
        ADL3STATbits.ADLIF = 0;
        dataValid = true;
    }
    return dataValid;
}

bool PADC1_AccumulationResultGet(uint32_t *accBuffer)
{
    bool dataValid = false;
    if(ADSTATLbits.ACCIF != 0)
    {
       *accBuffer = ACRESH; // Read result from accumulator.
       *accBuffer <<= 16;
       *accBuffer |= ACRESL;
       
       //Reload accumlator values
       ACRESL = 0; // Set initial value for the accumulator.
       ACRESH = 0;
       ACCONLbits.COUNT = (uint8_t)PADC1_ACC_NUM_SAMPLES; // Accumulate samples again.
       ACCONHbits.ACEN = 1; // Reenable accumulator.
       ADSTATLbits.ACCIF = 0; // Reset accumulator interrupt flag.
       dataValid = true;
    }
    return dataValid;
}

bool PADC1_SampleList0IsConversionDone(void)
{
   return(ADSTATLbits.SL0IF);
}

bool PADC1_SampleList1IsConversionDone(void)
{
   return(ADSTATLbits.SL1IF);
}

bool PADC1_SampleList2IsConversionDone(void)
{
   return(ADSTATLbits.SL2IF);
}

bool PADC1_SampleList3IsConversionDone(void)
{
   return(ADSTATLbits.SL3IF);
}

bool PADC1_IsAccumulationDone(void)
{
   return(ADSTATLbits.ACCIF);
}

void __attribute__ ((weak)) PADC1_CallBack(void)
{
    // Add your custom callback code here
}

void PADC1_Tasks( void )
{
    if(IFS0bits.AD1IF)
    {
		// PADC1 callback function 
		PADC1_CallBack();
        IFS0bits.AD1IF = 0;
    }
}