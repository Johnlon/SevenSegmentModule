/*
 * Implements a two digit seven segment common cathode display driver.
 * The same approach will also drive a common anode with the same PCB 
 * layout by reversing the high/low logic of the pins below.
 */

#include "mcc_generated_files/mcc.h"

void display(int dig) {
    
    int value4Bit;
    if (dig == 0) {
        value4Bit = DIN_0_GetValue() +
            (DIN_1_GetValue() << 1) +
            (DIN_2_GetValue() << 2) +
            (DIN_3_GetValue() << 3);
    } else {
        value4Bit = DIN_4_GetValue() +
            (DIN_5_GetValue() << 1) +
            (DIN_6_GetValue() << 2) +
            (DIN_7_GetValue() << 3);
    }
    bool a, b, c, d, e, f, g;
    a = b = c = d = e = f = g = false;

    switch (value4Bit) {
        case 0:
            a = b = c = d = e = f = true;
            break;
        case 1:
            b = c = true;
            break;
        case 2:
            a = b = e = d = g = true;
            break;
        case 3:
            a = b = c = d = g = true;
            break;
        case 4:
            b = c = f = g = true;
            break;
        case 5:
            a = c = d = f = g = true;
            break;
        case 6:
            a = c = d = e = f = g = true;
            break;
        case 7:
            a = b = c = true;
            break;
        case 8:
            a = b = c = d = e = f = g = true;
            break;
        case 9:
            a = b = c = d = f = g = true;
            break;
        case 10:
            a = b = c = d = e = g = true;
            break;
        case 11:
            c = d = e = f = g = true;
            break;
        case 12:
            a = d = e = f = true;
            break;
        case 13:
            b = c = d = e = g = true;
            break;
        case 14:
            a = d = e = f = g = true;
            break;
        case 15:
            a = e = f = g = true;
            break;
    }

    DIGIT_L_SetHigh(); // inactive
    DIGIT_H_SetHigh(); // inactive
   
    if (a) {
        SEG_A_SetHigh();
    } else {
        SEG_A_SetLow();
    }
    if (b) {
        SEG_B_SetHigh();
    } else {
        SEG_B_SetLow();
    }
    if (c) {
        SEG_C_SetHigh();
    } else {
        SEG_C_SetLow();
    }
    if (d) {
        SEG_D_SetHigh();
    } else {
        SEG_D_SetLow();
    }
    if (e) {
        SEG_E_SetHigh();
    } else {
        SEG_E_SetLow();
    }
    if (f) {
        SEG_F_SetHigh();
    } else {
        SEG_F_SetLow();
    }
    if (g) {
        SEG_G_SetHigh();
    } else {
        SEG_G_SetLow();
    }
 
    if (dig == 0) {
        DIGIT_L_SetLow(); // active
    } else {
        DIGIT_H_SetLow(); // active
    }
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
        display(0);
        __delay_us(10);

        display(1);
        __delay_us(10);
    }
}

/**
 End of File
 */
