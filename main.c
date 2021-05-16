/*
 * Implements a two digit seven segment common cathode display driver.
 * The same approach will also drive a common anode with the same PCB 
 * layout by reversing the high/low logic of the pins below.
 */

#include "mcc_generated_files/mcc.h"

int readInput() {
    // MK11 PCB layout accident
    bool mk2 = false;

    // MK1 DM9368 - not pic 
    // MK2 PIC WITH WINGS BUT WIRING WRONG
    // MK3 SKINNY 
// #define BAD_BCB_WIRING
    
#ifndef BAD_BCB_WIRING
    
        return 
            (DIN_0_GetValue() << 0) +
            (DIN_1_GetValue() << 1) +
            (DIN_2_GetValue() << 2) +
            (DIN_3_GetValue() << 3) +
            (DIN_4_GetValue() << 4) +
            (DIN_5_GetValue() << 5) +
            (DIN_6_GetValue() << 6) +
            (DIN_7_GetValue() << 7);
#else
        return 
            (DIN_0_GetValue() << 3) +
            (DIN_1_GetValue() << 2) +
            (DIN_2_GetValue() << 1) +
            (DIN_3_GetValue() << 0) +
            (DIN_4_GetValue() << 4) +
            (DIN_5_GetValue() << 5) +
            (DIN_6_GetValue() << 6) +
            (DIN_7_GetValue() << 7);
#endif
        
    }


void display(int dig, int v) {

    bool a; 
    bool b;
    bool c;
    bool d;
    bool e;
    bool f;
    bool g;
    
    a = b = c = d = e = f = g = false;

    switch (v) {
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

    // turn off display
    DIGIT_L_LAT = 1; // inactive
    DIGIT_H_LAT = 1; // inactive
    
    SEG_A_LAT = a;
    SEG_B_LAT = b;
    SEG_C_LAT = c;
    SEG_D_LAT = d;
    SEG_E_LAT = e;
    SEG_F_LAT = f;
    SEG_G_LAT = g;
    
    if (dig == 0) {
        DIGIT_L_LAT = 0; // active
    } else {
        DIGIT_H_LAT = 0; // active
    }
}

// make this long enough that the display is mostly on.
void sleep() {
    int i = 2;
    while (i-->0) {
        // pass
    }
}

/*
                         Main application
 */
#define LOWER 0
#define UPPER 1

void main(void) {
    SYSTEM_Initialize();

    while (1) {
        
        unsigned int sample = readInput();

        // Add your application code
        display(LOWER, sample & 0x0f);
        sleep();
        __delay_us(500);
        
        readInput();

        display(UPPER, sample >> 4);
        sleep();
        __delay_us(500);
    
    }
}


/**
 End of File
 */
