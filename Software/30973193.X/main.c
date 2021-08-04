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
typedef struct
{
    unsigned char upperCounter;
    unsigned char lowerCounter;
}Counter_t;


char upperCounter = 4, lowerCounter = 5;
typedef enum {ON, OFF} MODE;
MODE status = OFF;
/*
                         Main application
 */

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    Counter_t savedCounter, currentCounter;
    currentCounter.upperCounter = 5;
    currentCounter.lowerCounter = 4;
    savedCounter.upperCounter = 5;
    savedCounter.lowerCounter = 4;
    
    IO_RC1_SetLow();
    IO_RC2_SetLow();
    while (1)
    {
        /*ON-OFF touch pad */
        if(ON_OFF_GetValue() == 0)
        {
            __delay_ms(100);
            if(ON_OFF_GetValue() == 0)
            {
                LED_Toggle();
                if(status == OFF)
                {
                    status = ON;
                    /*Turn off all LEDs */
                    for(int i = 0; i < 10; i++)
                    {
                        Upper_LED[i](false);
                        Lower_LED[i](false);
                    }
                    /*Turn on forward */
                    for(int i = 0; i < 10; i++)
                    {
                        Upper_LED[i](true);
                        Lower_LED[i](true);
                        __delay_ms(50);
                    }
                    for(int i = 9; i >= 0; i--)
                    {
                        Upper_LED[i](false);
                        Lower_LED[i](false);
                        __delay_ms(100);
                    }
                    for(int i = 0; i < (currentCounter.upperCounter > currentCounter.lowerCounter ? currentCounter.lowerCounter : currentCounter.upperCounter); i++)  
                    {
                        Upper_LED[i](true);
                        Lower_LED[i](true);
                        __delay_ms(50);
                    }
                    for(int i = (currentCounter.upperCounter > currentCounter.lowerCounter ? currentCounter.lowerCounter : currentCounter.upperCounter); i < (currentCounter.upperCounter < currentCounter.lowerCounter ? currentCounter.lowerCounter : currentCounter.upperCounter); i++)
                    {
                        if (currentCounter.upperCounter > currentCounter.lowerCounter)
                            Upper_LED[i](true);
                        else if (currentCounter.upperCounter < currentCounter.lowerCounter)
                            Lower_LED[i](true);
                        else
                            break;
                        __delay_ms(50);
                    }
                }
                else
                {
                    status = OFF;
                    for(int i = 0; i < 10; i++)
                    {
                        Upper_LED[i](false);
                        Lower_LED[i](false);
                    }
                }
            }
        }
        /*W-UP touch pad */
        if((W_UP_GetValue() == 0)&&(currentCounter.upperCounter < 10))
        {
            __delay_ms(100);
            if(W_UP_GetValue() != 0)
                currentCounter.upperCounter++;
            else if(W_UP_GetValue() == 0)
            {
                __delay_ms(400);
                currentCounter.upperCounter++;
            }
                
        }
        /*Y-UP touch pad */
        if((Y_UP_GetValue() == 0)&&(currentCounter.lowerCounter < 10))
        {
            __delay_ms(100);
            if(Y_UP_GetValue() != 0)
                currentCounter.lowerCounter++;
            else if(Y_UP_GetValue() == 0)
            {
                __delay_ms(400);
                currentCounter.lowerCounter++;
            }
        }
        /* W-DOWN touch pad */
        if((W_DOWN_GetValue() == 0)&&(currentCounter.upperCounter > 0))
        {
            __delay_ms(100);
            if(W_DOWN_GetValue() != 0)
                currentCounter.upperCounter--;
            else if(W_DOWN_GetValue() == 0)
            {
                __delay_ms(400);
                currentCounter.upperCounter--;
            }
        }
        /* Y-DOWN touch pad */
        if((Y_DOWN_GetValue() == 0)&&(currentCounter.lowerCounter > 0))
        {
            __delay_ms(100);
            if(Y_DOWN_GetValue() != 0)
                currentCounter.lowerCounter--;
            else if(Y_DOWN_GetValue() == 0)
            {
                __delay_ms(400);
                currentCounter.lowerCounter--;
            }
        }
        /*M1 touch pad */
        /*M2 touch pad */
        if(M2_GetValue() == 0)
        {
            
            __delay_ms(400);
            if(M2_GetValue() != 0)
            {
                /*Restore saved counter. */
                currentCounter.upperCounter = savedCounter.upperCounter;
                currentCounter.lowerCounter = savedCounter.lowerCounter;
            }
            else if(M2_GetValue() == 0)
            {
                /*Save new counter */
                savedCounter.upperCounter = currentCounter.upperCounter;
                savedCounter.lowerCounter = currentCounter.lowerCounter;
            }
            
        }
        // Add your application code
        switch(status)
        {
            case ON:
            {
                
                for (int i = 0; i < currentCounter.upperCounter; i++)
                {
                    Upper_LED[i](true);
                }
                for (int i = currentCounter.upperCounter; i < 10; i++)
                {
                    Upper_LED[i](false);
                }
                for (int i = 0; i < currentCounter.lowerCounter; i++)
                {
                    Lower_LED[i](true);
                }
                
                for (int i = currentCounter.lowerCounter; i < 10; i++)
                {
                    Lower_LED[i](false);
                }
                
            }
            break;
            case OFF:
            {
                Upper_LED[savedCounter.upperCounter - 1](true);
                Lower_LED[savedCounter.lowerCounter - 1](true);
            }
            break;
            default : break;
        }
    }
     
}
/**
 End of File
*/