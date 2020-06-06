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
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.145.0
        Device            :  PIC24FJ64GC006
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36b
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

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#define FCY 16000000UL
#include <libpic30.h>
#define LCD_ADR 0x3E

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
    writeLCDCommand(0x7e);// contast LSB setting ; 0b0111 xxxx
    writeLCDCommand(0x55);// 5V=0b0101 00xx, 3V=0b0101 01xx,  xx=contrast MSB
    writeLCDCommand(0x6C);
    __delay_ms(250);
    writeLCDCommand(0x38);
    writeLCDCommand(0x01);
    __delay_us(1100);        //Instruction Execution Time 0.59-1.08ms (550:NG, 600:GOOD)
    writeLCDCommand(0x0C);
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
/*
                         Main application
 */
int main(void)
{
    // initialize the device
    DSCON = 0x0000; // must clear RELEASE bit after Deep Sleep
    DSCON = 0x0000; // must be write same command twice
    SYSTEM_Initialize();
    LCD_Init();
    char c0[17]="HELLO WORLD !";

    while (1)
    {
        // Add your application code
        PORTEbits.RE0 = 1;
        __delay_ms(2000);
        LCD_xy(0,0);LCD_str2(c0);
        __delay_ms(2000);
        LCD_xy(0,1);LCD_str2(c0);
        __delay_ms(2000);
        LCD_clear();
        __delay_ms(2000);
        PORTEbits.RE0 = 0;
        DSCON = 0x8000; // deep sleep mode  0.3uA ! (DSCON=0x0000 --> 360uA)
        DSCON = 0x8000; // must be write same command twice
        Sleep();
    }

    return 1;
}
/**
 End of File
*/

