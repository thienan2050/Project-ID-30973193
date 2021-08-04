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
        Device            :  PIC16F1939
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
void (* Upper_LED[10])(bool) = {setA0, setE1, setA6, setC3, setD1, setD3, setC5, setC7, setD5, setD7};
void (* Lower_LED[10])(bool) = {setA2, setA3, setA7, setC0, setD0, setD2, setC4, setC6, setD4, setD6};
char upperCounter = 4, lowerCounter = 5;
/*
                         Main application
 */

void main(void)
{
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
    /*
    while(1)
    {
        if(W_UP_GetValue() == 0)
        {
            Upper_LED[1](true);
            while(W_UP_GetValue() == 0);
        }
            
        else
            Upper_LED[1](false);
    }
    */
    
    IO_RC1_SetLow();
    IO_RC2_SetLow();
    while (1)
    {
        if((W_UP_GetValue() == 0)&&(upperCounter < 10))
        {
            while(W_UP_GetValue() == 0);
            upperCounter++;
        }
        if((Y_UP_GetValue() == 0)&&(lowerCounter < 10))
        {
            while(Y_UP_GetValue() == 0);
            lowerCounter++;
        }
        if((W_DOWN_GetValue() == 0)&&(upperCounter > 0))
        {
            while(W_DOWN_GetValue() == 0);
            upperCounter--;
        }
        if((Y_DOWN_GetValue() == 0)&&(lowerCounter > 0))
        {
            while(Y_DOWN_GetValue() == 0);
            lowerCounter--;
        }
        
        // Add your application code
        for (int i = 0; i < upperCounter; i++)
        {
            Upper_LED[i](true);
        }
        for(int i = upperCounter; i < 10; i++)
        {
            Upper_LED[i](false);
        }
        for (int i = 0; i < lowerCounter; i++)
        {
            Lower_LED[i](true);
        }
        for(int i = lowerCounter; i < 10; i++)
        {
            Lower_LED[i](false);
        }

    }
     
}
/**
 End of File
*/