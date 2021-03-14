/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18446
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 

    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"

void display(int v, int dig) {
    
    if (dig==0) {
        DIGIT_L_SetLow();  // active
        DIGIT_H_SetHigh(); // inactive
    } else {
        DIGIT_L_SetHigh(); // inactive
        DIGIT_H_SetLow();  // active
    }
    
    bool a,b,c,d,e,f,g;
     a=b=c=d=e=f=g = false;
            
    switch (v) {
        case 0:
            a=b=c=d=e=f = true;
            break;
        case 1:
            b=c=true;
            break;
        case 2:
            a=b=e=d=g=true;
            break;
        case 3:
            a=b=c=d=g=true;
            break;
        case 4:
            b=c=f=g=true;
            break;
        case 5:
            a=c=d=f=g=true;
            break;
        case 6:
            a=c=d=e=f=g=true;
            break;
        case 7:
            a=b=c=true;
            break;
        case 8:
            a=b=c=d=e=f=g=true;
            break;
        case 9:
            a=b=c=d=f=g=true;
            break;
        case 10:
            a=b=c=d=e=g=true;
            break;
        case 11:
            c=d=e=f=g=true;
            break;
        case 12:
            a=d=e=f=true;
            break;
        case 13:
            b=c=d=e=g=true;
            break;
        case 14:
            a=d=e=f=g=true;
            break;
        case 15:
            a=e=f=g=true;
            break;
    }
    
    if (a) {SEG_A_SetHigh();} else {SEG_A_SetLow();}
    if (b) {SEG_B_SetHigh();} else {SEG_B_SetLow();}
    if (c) {SEG_C_SetHigh();} else {SEG_C_SetLow();}
    if (d) {SEG_D_SetHigh();} else {SEG_D_SetLow();}
    if (e) {SEG_E_SetHigh();} else {SEG_E_SetLow();}
    if (f) {SEG_F_SetHigh();} else {SEG_F_SetLow();}
    if (g) {SEG_G_SetHigh();} else {SEG_G_SetLow();}
    
}
/*
                         Main application
 */
void main(void) {
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1) {
        // Add your application code
        int loByte = DIN_0_GetValue() +
                (DIN_1_GetValue() << 1) +
                (DIN_2_GetValue() << 2) +
                (DIN_3_GetValue() << 3);
        display(loByte, 0);
        __delay_ms(100000);
      
        int hiByte = DIN_4_GetValue() +
                (DIN_5_GetValue() << 1) +
                (DIN_6_GetValue() << 2) +
                (DIN_7_GetValue() << 3);
        display(hiByte, 1);
        __delay_ms(100000);
    }
}

/**
 End of File
 */
