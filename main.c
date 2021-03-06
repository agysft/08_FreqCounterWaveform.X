/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
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

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/spi1.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/tmr5.h"
#define FCY 16000000UL
#include <libpic30.h>
#include <stdio.h>
#include <p24FJ64GC006.h>
#include "mcc_generated_files/rtcc.h"
#include "font_ascii.h"
#include "font1216.h"
#define LCD_ADR 0x3E    // I2C address of the character LCD

// frequency counter
unsigned int overflowCounter;

// rotaly encoder
int pressedTime = 0;
int rotData, rotDir, swPos; float rotVal;

//Time axis setting table
    /*
     *          PR2
     * 250ns    0x03
     * 500ns    0x07
     *   1us    0x0f
     * 2.5us    0x27
     *   5us    0x4f
     *  10us    0x9f
     *  25us    0x18f
     *  50us    0x31f
     * 100us    0x63f
     * 250us    0xF9F
     */
uint8_t TimeAxisTableIndex = 2;
uint16_t TimeAxisTable[]={3, 7, 0x0f, 0x27, 0x4f, 0x9f, 0x18f, 0x31f, 0x63f, 0xf9f};
char TimeAxisTable_s[10][6]={"250ns","500ns","  1us","2.5us","  5us"," 10us"," 25us"," 50us","100us","250us"};

// function mode
int ModeVal = 1;
    
//------------------------------------------------------------------------------ 
//Public prototypes 
//------------------------------------------------------------------------------ 
void i2c_START();
void i2c_TXDAT(char data);
void i2c_SENDACK();
void i2c_SENDNACK();
void i2c_STOP();
void writeLCDData(char t_data);
void writeLCDCommand(char t_command);
void LCD_Init();
void LCD_xy(uint8_t x, uint8_t y);
void LCD_str(char *c);
void LCD_str2(char *c);
//------------------------------------------------------------------------------

void i2c_START(){
    IFS1bits.MI2C1IF = 0;
    I2C1CONbits.SEN = 1;
    while (IFS1bits.MI2C1IF == 0) {}
    IFS1bits.MI2C1IF = 0;
}

void i2c_TXDAT(char data){
    IFS1bits.MI2C1IF = 0;
    I2C1TRN = data;
    while (IFS1bits.MI2C1IF == 0) {}
    IFS1bits.MI2C1IF = 0;
}

void i2c_SENDACK(){
    I2C1CONbits.ACKDT = 0;
    I2C1CONbits.ACKEN = 1;
    while (I2C1CONbits.ACKEN) {}
}

void i2c_SENDNACK(){
    I2C1CONbits.ACKDT = 1;
    I2C1CONbits.ACKEN = 1;
    while (I2C1CONbits.ACKEN) {}
}

void i2c_STOP(){
    I2C1CONbits.PEN = 1;
    while (I2C1CONbits.PEN == 1) {}
    IFS1bits.MI2C1IF = 0;
}

void writeLCDData(char t_data){
    i2c_START();
    i2c_TXDAT(LCD_ADR<<1);
    i2c_TXDAT(0x40);
    i2c_TXDAT(t_data);
    i2c_STOP();
}

void writeLCDCommand(char t_command){
    i2c_START();
    i2c_TXDAT(LCD_ADR<<1);
    i2c_TXDAT(0x00);
    i2c_TXDAT(t_command);
    i2c_STOP();
    __delay_us(30);     //Instruction Execution Time 14.3-26.3us
}

void LCD_Init(){
    I2C1CON = 0b1000001000000000;   // I2C1 enaable RD9=SDA1, RD10=SCL1
    I2C1BRG = 0x25;         //set I2C board rate to 400KHz
    __delay_ms(10);
    
    writeLCDCommand(0x38);
    writeLCDCommand(0x39);
    writeLCDCommand(0x14);
    writeLCDCommand(0x70);// contast LSB setting ; 0b0111 xxxx
    writeLCDCommand(0x56);// 5V=0b0101 00xx, 3V=0b0101 01xx,  xx=contrast MSB
    writeLCDCommand(0x6C);
    __delay_ms(250);
    writeLCDCommand(0x38);
    writeLCDCommand(0x01);
    __delay_us(1100);        //Instruction Execution Time 0.59-1.08ms (550:NG, 600:GOOD)
    writeLCDCommand(0x0c);
}
void LCD_OFF(){
    writeLCDCommand(0x08);
    writeLCDCommand(0x50);
    writeLCDCommand(0x60);
}

void LCD_xy(uint8_t x, uint8_t y){
    writeLCDCommand(0x80 + 0x40 * y + x);
}

void LCD_str(char *c) {
    unsigned char i,wk;
    for (i=0 ;i<16 ; i++) {
        wk = c[i];
        if  (wk == 0x00) {break;}
        writeLCDData(wk);
    }
}

void LCD_str2(char *c) {
    unsigned char wk;
    int i;
    i2c_START();
    i2c_TXDAT(LCD_ADR<<1);
    for (i=0;i<16;i++){
        wk = c[i];
        if  (wk == 0x00) {break;}
        i2c_TXDAT(0xc0);
        i2c_TXDAT(wk);
    }
    i2c_STOP();
    __delay_us(30);
}

void LCD_clear(){
    writeLCDCommand(0x01);
    __delay_us(1100);        //Instruction Execution Time 0.59-1.08ms (550:NG, 600:GOOD)
}

void GLCD_COM(uint8_t acommand){
    uint8_t tmpcommand;
    PORTDbits.RD4 = 0;  //command
    tmpcommand = SPI1_Exchange8bit(acommand);
}
void GLCD_DAT(uint8_t acommand){
    uint8_t tmpcommand;
    PORTDbits.RD4 = 1;  //data
    tmpcommand = SPI1_Exchange8bit(acommand);
}

void GLCD_Init(){
    PORTDbits.RD3 = 0;  //CS=enable
    __delay_us(10);
    GLCD_COM(0xAE);
    GLCD_COM(0xA0);
    GLCD_COM(0xC8);
    GLCD_COM(0xA3);
    GLCD_COM(0x2C);
    __delay_ms(2);
    GLCD_COM(0x2E);
    __delay_ms(2);
    GLCD_COM(0x2F);
    GLCD_COM(0x23);
    GLCD_COM(0x81);
    GLCD_COM(0x1a); // contrast 00 - 3F
    GLCD_COM(0xA4);
    GLCD_COM(0x40);
    GLCD_COM(0xA6);
    GLCD_COM(0xAF);
}

void GLCD_OFF(){
    GLCD_COM(0xAE);
}

void GLCD_Plot(uint8_t x, uint8_t y){
    uint8_t i;
    for(i=0;i<6;i++){
        GLCD_COM(0xb0 + i); // set page address 0..5
        GLCD_COM(0x10 | (y >> 4));  // column address upper 4bits
        GLCD_COM(y & 0x0f);         // column address lower 4bits
        if ( i == 5 - (x >> 3)){
            GLCD_DAT(0x80 >> (x & 0x7));
        } else {
            GLCD_DAT(0x00);
        }
    }
}

void GLCD_LineHL(uint8_t xH, uint8_t xL, uint8_t t){
    union {
        unsigned long long gdat64;
        uint8_t gdat8[8];
    } GDAT;
    uint8_t dx, xT;
    uint8_t i;
    if (xH > 47) xH = 47;
    if (xL > 47) xL = 47;
    if (xH > xL){
        dx = xH - xL;
    } else if (xH < xL){
        dx = xL - xH;
        xT = xH;
        xH = xL;
        xL = xT;
    } else dx = 1;
    if ( (xH | xL) == 0 ) xH = 1;
    GDAT.gdat64 = 0xffffffffffffffff;
    GDAT.gdat64 = GDAT.gdat64 << xL;    // white line
    GDAT.gdat64 = ~(GDAT.gdat64);
    GDAT.gdat64 = GDAT.gdat64 << dx;    // black line
    GDAT.gdat64 = ~(GDAT.gdat64);
    GDAT.gdat64 = GDAT.gdat64 << (48 - xH); // white line
    for(i=0;i<6;i++){
        GLCD_COM(0x10 | (t >> 4));  // column address upper 4bits
        GLCD_COM(t & 0x0f);         // column address lower 4bits
        GLCD_COM(0xb0 + i); // set page address 0..5
        GLCD_DAT(GDAT.gdat8[i]);
    }
}

void GLCD_printxy(uint8_t x, uint8_t y, char cDat[]){
    uint8_t i;
    GLCD_COM(0xb0 | (0x0f & y));// set page address 0..5
    GLCD_COM(0x10 | (x >> 4));  // column address upper 4bits
    GLCD_COM(x & 0x0f);         // column address lower 4bits
    for(x = 0; (x < 16) && ( cDat[x] != '\0'); x++){
        for(i=0;i<8;i++){
            GLCD_DAT(font[cDat[x] - ' '][i]);
        }
    }
}

void GLCD_print1216xy(uint8_t xin, uint8_t yin, char cDat[]){
    uint8_t i,x;
    GLCD_COM(0xb0 | (0x0f & yin));// set page address 0..4
    GLCD_COM(0x10 | (xin >> 4));  // column address upper 4bits
    GLCD_COM(xin & 0x0f);         // column address lower 4bits
    for(x = 0; (x < 11) && ( cDat[x] != '\0'); x++){
        for(i=0;i<12;i++){
            GLCD_DAT( (uint8_t)((font1216[cDat[x] - ' '][i] & 0x00ff) ) );
        }
    }
    GLCD_COM(0xb0 | ( 0x0f & (yin+1) ));// set page address 1..5
    GLCD_COM(0x10 | (xin >> 4));  // column address upper 4bits
    GLCD_COM(xin & 0x0f);         // column address lower 4bits
    for(x = 0; (x < 11) && ( cDat[x] != '\0'); x++){
        for(i=0;i<12;i++){
            GLCD_DAT( (uint8_t)((font1216[cDat[x] - ' '][i]) >> 8) );
        }
    }
}

void TMR1_int(){
    // when overflow 16bit counter TMR1
    overflowCounter++;
}

void EX_INT1_CallBack(){
    // pushed the switch of the rotary encoder
    IFS1bits.T5IF = false;
    IEC1bits.T5IE = true;   // enable detection of the rotary encoder
}

void TMR5_int(){
    // Interrupt occurs every 20ms; 
    //  for detection of the rotary encoder and
    //  for detection of the pressed time of the SW
    if (PORTFbits.RF3 == 0) pressedTime++;
    rotData = ((rotData & 0x3) << 2) | (PORTF & 0x3);
    switch(rotData){
        case 0b0010 :
        case 0b1011 :
        case 0b1101 :
        case 0b0100 : 
            rotVal-= 0.5;
            rotDir = -1;
            return;

        case 0b0001 :
        case 0b0111 :
        case 0b1110 :
        case 0b1000 : 
            rotVal+= 0.5;
            rotDir = 1;
            return;

        default: 
            rotDir = 0;
            return;
    }
}

void DisplayCurrentDateAndTime(bcdTime_t currentTime, char *c0){
    RTCC_BCDTimeGet( &currentTime );
    sprintf(c0, "20%02x/%02x/%02x %02x:%02x", 
            currentTime.tm_year, currentTime.tm_mon, 
            currentTime.tm_mday, //currentTime.tm_wday
            currentTime.tm_hour, currentTime.tm_min 
            );
    LCD_xy(0,1);LCD_str2(c0);
}

void DisplayCurrentTime2GLCD(bcdTime_t currentTime, char *c0){
    RTCC_BCDTimeGet( &currentTime );
    sprintf(c0, "%02x/%02x ", 
            //currentTime.tm_year, 
            currentTime.tm_mon, 
            currentTime.tm_mday //, currentTime.tm_wday
            //currentTime.tm_hour, currentTime.tm_min 
            );
    //LCD_xy(0,1);LCD_str2(c0);
    GLCD_print1216xy(0,0,c0);
    sprintf(c0, "%02x:%02x", 
            //currentTime.tm_year, currentTime.tm_mon, 
            //currentTime.tm_mday, //currentTime.tm_wday
            currentTime.tm_hour, currentTime.tm_min 
            );
    //LCD_xy(0,1);LCD_str2(c0);
    GLCD_print1216xy(68,0,c0);
}

void EX_INT0_CallBack(){
    ModeVal = 10;
}

uint8_t ConvertHexToBCD(uint8_t hexvalue)
{
    uint8_t bcdvalue;
    bcdvalue = (hexvalue / 10) << 4;
    bcdvalue = bcdvalue | (hexvalue % 10);
    return bcdvalue;
}

uint8_t ConvertBCDToHex(uint8_t bcdvalue)
{
    uint8_t hexvalue;
    hexvalue = (((bcdvalue & 0xF0) >> 4)* 10) + (bcdvalue & 0x0F);
    return hexvalue;
}

/*
                         Main application
 */
int main(void)
{
    char c0[17]="HELLO WORLD !";
    int i, t0;
    
    union {
        unsigned long dat32;
        uint16_t dat16[2];
    } UDAT;
    
    #define THLVL   2047    // Threshold level; for edge detection of waveform; Resolution of PADC is 12 bits
    #define Hysteresis  1   // Reduce noise on the voltage axis
    #define DetectionInterval   2   // Reduce noise on the time axis
    uint16_t originalWavedata[256];
    uint8_t byteWavedata[128], prev_gx, gx;

    bcdTime_t currentTime, setTime;
    uint8_t arrayDateTime[6];

    // initialize the device
    DSCON = 0x0000; // must clear RELEASE bit after Deep Sleep
    DSCON = 0x0000; // must be write same command twice
    SYSTEM_Initialize();
    DAC2DAT = 512;  // Center BIAS
    TMR1_SetInterruptHandler(TMR1_int);
    TMR5_SetInterruptHandler(TMR5_int);

    LCD_Init();
    GLCD_Init();
    // Demo
    PORTEbits.RE0 = 1;          // Turn on LEFT-UP blue LED
    PORTGbits.RG2 = 1;          // Turn on rotary-encoder blue LED
    LCD_xy(0,0);LCD_str2(c0);   // Display "HELLO.."
    for (i=0;i<128;i++){        // Test Gfx LCD
            GLCD_LineHL(i & 0x1f,(i & 0x1f)+16,i);
    }
    __delay_ms(2000);   // Test Display 2sec
    //GLCD_printxy(12, 2, "HELLO WORLD !");
    GLCD_print1216xy(0,0,"           ");    //clear GLCD
    GLCD_print1216xy(0,4,"           ");    //clear GLCD
    GLCD_print1216xy(0,1,"  HELLO    ");
    GLCD_print1216xy(0,3,"   WORLD!  ");
    //DisplayCurrentTime2GLCD(currentTime, c0); //for test
    //__delay_ms(20000);   // Test Display 2sec
    DisplayCurrentDateAndTime(currentTime, c0);
    __delay_ms(2000);   // Test Display 2sec
    LCD_clear();
    //PORTEbits.RE0 = 0;  //Turn off the LED
    /*
     * Select the Input
     */
    PORTBbits.RB4 = 1;
    PORTBbits.RB3 = 0;
    PORTBbits.RB2 = 0;


    /*** DMA CH0 Setting ****/
	DMACONbits.DMAEN = 1;               // DMA Enable
	DMACONbits.PRSSEL = 0;              // Fixed Priority
	DMAH = 0x2000;                      // Upper Limit
	DMAL = 0x800;                       // Lower Limit
	DMACH0 = 0;                         // Stop Channel
	DMACH0bits.RELOAD = 1;              // Reload DMASRC, DMADST, DMACNT
	DMACH0bits.TRMODE = 0b00;           // Oneshot    
	DMACH0bits.SAMODE = 0;              // Source Addrs No Increment
	DMACH0bits.DAMODE = 1;              // Dist Addrs Increment
	DMACH0bits.SIZE = 0;                // Word Mode(16bit)
	DMASRC0 = (unsigned int)&ADRES0;    // From ADC Buf0 select
	DMADST0 = (unsigned int)originalWavedata;  // To Buffer select
	DMACNT0 = 256;                      // DMA Counter
	DMAINT0 = 0;                        // All Clear
	DMAINT0bits.CHSEL = 0x2F;           // Select Pipeline ADC
	DMACH0bits.CHEN = 0;                // Channel DisableEnable
	IFS0bits.DMA0IF = 0;                // Flag Reset
    T2CONbits.TON = 0;                  // stop Timer2

    IEC1bits.T5IE = false;      // disable TMR5 interrupt; stop detection of the rotary encoder
    PORTGbits.RG3 = 0; // clear orage LED
    PORTGbits.RG2 = 0; // clear blue LED
    sprintf(c0, "T %5s ", TimeAxisTable_s[TimeAxisTableIndex]); LCD_xy(0,1);LCD_str2(c0);
    sprintf(c0, "   L %3d", DAC2DAT/35); LCD_xy(8,1);LCD_str2(c0);
    while (1)
    {
        // Add your application code
        if (ModeVal ==1){
            PORTGbits.RG3 = 0; // clear orage LED
            PORTGbits.RG2 = 0; // clear blue LED
            /*** Frequency Count ***/
            IEC1bits.T5IE = false;
            overflowCounter = 0;
            TMR3 = 0; PR3 = 62499;      // 16MHz/256/62500=1Hz
            TMR1 = 0; PR1 = 0xffff;     // Interrupt when 16bit counter overflow
            IFS0bits.T3IF = 0;
            T3CONbits.TON = 1;
            T1CONbits.TON = 1;
            while(IFS0bits.T3IF == 0);
            T1CONbits.TON = 0;
            T3CONbits.TON = 0;
            IFS0bits.T3IF = 0;
            UDAT.dat16[0] = TMR1;
            UDAT.dat16[1] = overflowCounter;
            sprintf(c0, "FRQ   %8luHz",  UDAT.dat32);
            LCD_xy(0,0);LCD_str2(c0);
        }
        
        if (ModeVal < 4){
            /*** Get Waveform 256 word ***/
            ADCON1bits.ADON = 1;    // ADC Enable
            TMR2 = 0;               // reset Timer2
            ADSTATLbits.SL0IF = 0;  // ADC Flag Clear
            IFS0bits.DMA0IF = 0;    // DMA Interrupt Flag Reset
            T2CONbits.TON = 1;		// start Timer2 = start ADC
            DMACH0bits.CHEN = 1;    // DMA Channel Enable & Start
            while(IFS0bits.DMA0IF == 0);	// Wait Max_Size sampling
            T2CONbits.TON = 0;      // stop Timer2 = stop ADC
            IFS0bits.DMA0IF = 0;	// Clear DMA Interrupt Flag
            DMACH0bits.CHEN = 0;    // DMA Channel Disable & Stop
            ADCON1bits.ADON = 0;    // ADC Disable

            // edge detect = seek rising/falling edge
            for (i=0;i<125;i++){
                if ( originalWavedata[i] > (THLVL - Hysteresis) && originalWavedata[i+DetectionInterval] <= (THLVL + Hysteresis) ){
                    break;
                }
            }
            t0 = i;
            // prepare data for display
            for (i=0;i<128;i++){
                byteWavedata[i] = originalWavedata[i+t0] / 86;    //0..4095 -> 0..47
            }
            // Scale Display
            prev_gx = byteWavedata[0];
            for (i=0;i<128;i++){
                gx = byteWavedata[i];
    //            GLCD_Plot(gx,i);
                GLCD_LineHL(prev_gx, gx, i);
                prev_gx = gx;
            }
//            if (ModeVal == 1){    /*Test Program for font*/
//                //GLCD_printxy(0,5,c0);
//                sprintf(c0, "F             Hz",  UDAT.dat32);
//                GLCD_printxy(0,5,c0);
//                sprintf(c0, "%8lu",  UDAT.dat32);
//                GLCD_print1216xy(16,4,c0);                
//            }
        }
        
        if (pressedTime > 0){
            while (PORTFbits.RF3 == 0){}    // Wait until switch is released
            if (pressedTime < 100){
                ModeVal++;
                if (ModeVal == 4) ModeVal = 1;
                PORTGbits.RG2 = 1; // Turn on the blue LED
                if (ModeVal == 2){
                    rotVal = TimeAxisTableIndex;
                    LCD_xy(0,0);LCD_str2("Time/div        ");
                    sprintf(c0, "T %5s ", TimeAxisTable_s[TimeAxisTableIndex]); LCD_xy(0,1);LCD_str2(c0);
                }
                if (ModeVal == 3){
                    rotVal = (float)DAC2DAT/35;
                    LCD_xy(0,0);LCD_str2("Level Wave Pos  ");
                    sprintf(c0, "   L %3d",(int)rotVal); LCD_xy(8,1);LCD_str2(c0);
                }
                if (ModeVal > 3){
                    arrayDateTime[ModeVal-5] = rotVal;
                    rotVal = arrayDateTime[ModeVal-4];
                }
                if (ModeVal >8){
                    setTime.tm_year = ConvertHexToBCD((uint8_t) arrayDateTime[0]);
                    setTime.tm_mon  = ConvertHexToBCD((uint8_t) arrayDateTime[1]);
                    setTime.tm_mday = ConvertHexToBCD((uint8_t) arrayDateTime[2]);
                    setTime.tm_hour = ConvertHexToBCD((uint8_t) arrayDateTime[3]);
                    setTime.tm_min  = ConvertHexToBCD((uint8_t) arrayDateTime[4]);
                    RTCC_BCDTimeSet(&setTime);
                    LCD_clear();
                    ModeVal = 1;
                }
            } else {
                // When the switch is pressed for 2 seconds or more
                if (ModeVal < 4){
                    ModeVal = 4;
                } else ModeVal++;
                if (ModeVal == 4){
                    RTCC_BCDTimeGet( &currentTime );
                    setTime = currentTime;
                    arrayDateTime[0] = ConvertBCDToHex((uint8_t)setTime.tm_year);
                    arrayDateTime[1] = ConvertBCDToHex((uint8_t)setTime.tm_mon);
                    arrayDateTime[2] = ConvertBCDToHex((uint8_t)setTime.tm_mday);
                    arrayDateTime[3] = ConvertBCDToHex((uint8_t)setTime.tm_hour);
                    arrayDateTime[4] = ConvertBCDToHex((uint8_t)setTime.tm_min);
                    LCD_clear();
                    DisplayCurrentDateAndTime(currentTime, c0);
                    rotVal = arrayDateTime[0];
                }

                if (ModeVal>4){
                    ModeVal = 1;
                    setTime.tm_year = ConvertHexToBCD((uint8_t) arrayDateTime[0]);
                    setTime.tm_mon  = ConvertHexToBCD((uint8_t) arrayDateTime[1]);
                    setTime.tm_mday = ConvertHexToBCD((uint8_t) arrayDateTime[2]);
                    setTime.tm_hour = ConvertHexToBCD((uint8_t) arrayDateTime[3]);
                    setTime.tm_min  = ConvertHexToBCD((uint8_t) arrayDateTime[4]);
                    RTCC_BCDTimeSet(&setTime);
                    LCD_clear();
                }
            }
            pressedTime = 0;
        }
        
        if (ModeVal == 2){
            if (rotDir != 0){
                if (rotVal > 9) rotVal = 9;
                if (rotVal <= 0) rotVal = 0;
                TimeAxisTableIndex = (uint8_t)rotVal;
                PR2 = TimeAxisTable[TimeAxisTableIndex];
                sprintf(c0, "T %5s ", TimeAxisTable_s[TimeAxisTableIndex]); LCD_xy(0,1);LCD_str2(c0);
            }
        }
        
        if (ModeVal == 3){
            if (rotDir != 0){
                if (rotVal > 29) rotVal = 29;
                if (rotVal <= 0) rotVal = 0;
                DAC2DAT = (uint16_t)(rotVal*35);
                sprintf(c0, "   L %3d",(int)rotVal); LCD_xy(8,1);LCD_str2(c0);
            }
        }
        
        if (ModeVal == 4){
            sprintf(c0, "Set Year        "); LCD_xy(0,0); LCD_str2(c0);
            sprintf(c0, "%2d",(uint8_t)rotVal); LCD_xy(2,1); LCD_str2(c0);
        }

        if (ModeVal == 5){
            sprintf(c0, "Set Month      "); LCD_xy(0,0); LCD_str2(c0);
            sprintf(c0, "%2d",(uint8_t)rotVal); LCD_xy(5,1); LCD_str2(c0);
        }
        
        if (ModeVal == 6){
            sprintf(c0, "Set Date       "); LCD_xy(0,0); LCD_str2(c0);
            sprintf(c0, "%2d",(uint8_t)rotVal); LCD_xy(8,1); LCD_str2(c0);
        }

        if (ModeVal == 7){
            sprintf(c0, "Set Hour       "); LCD_xy(0,0); LCD_str2(c0);
            sprintf(c0, "%2d",(uint8_t)rotVal); LCD_xy(11,1); LCD_str2(c0);
        }

        if (ModeVal == 8){
            sprintf(c0, "Set Minute     "); LCD_xy(0,0); LCD_str2(c0);
            sprintf(c0, "%2d",(uint8_t)rotVal); LCD_xy(14,1); LCD_str2(c0);
        }
        //PORTEbits.RE0 = ~PORTEbits.RE0;
        //PORTGbits.RG3 = ~PORTGbits.RG3; //for test
        //PORTGbits.RG2 = ~PORTGbits.RG2; //for test
        if (ModeVal == 10){
            DisplayCurrentDateAndTime(currentTime, c0);
            DisplayCurrentTime2GLCD(currentTime, c0); //for test
            __delay_ms(5000);   // Test Display 5sec
            PORTEbits.RE0 = 0;          // Turn off LEFT-UP blue LED
            LCD_clear();
            GLCD_OFF();
            DSCON = 0x8000; // deep sleep mode  0.3uA ! (DSCON=0x0000 --> 360uA)
            DSCON = 0x8000; // must be write same command twice
            Sleep();
        }
    }

    return 1;
}
/**
 End of File
*/

