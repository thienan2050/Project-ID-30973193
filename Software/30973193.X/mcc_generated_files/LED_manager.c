/*
 * File:   LED_manager.c
 * Author: Thien An Bui
 *
 * Created on August 3, 2021, 9:45 AM
 */


#include "pin_manager.h"
#include "LED_manager.h"



/* Upper LEDs */
void setA0(bool status)
{
    if(status == true)
        IO_RA0_SetHigh();
    else
        IO_RA0_SetLow();    
}
void setE1(bool status)
{
    if(status == true)
        IO_RE1_SetHigh();
    else
        IO_RE1_SetLow();    
}
void setA6(bool status)
{
    if(status == true)
        IO_RA6_SetHigh();
    else
        IO_RA6_SetLow();    
}
void setC3(bool status)
{
    if(status == true)
        IO_RC3_SetHigh();
    else
        IO_RC3_SetLow();    
}
void setD1(bool status)
{
    if(status == true)
        IO_RD1_SetHigh();
    else
        IO_RD1_SetLow();    
}
void setD3(bool status)
{
    if(status == true)
        IO_RD3_SetHigh();
    else
        IO_RD3_SetLow();    
}
void setC5(bool status)
{
    if(status == true)
        IO_RC5_SetHigh();
    else
        IO_RC5_SetLow();    
}
void setC7(bool status)
{
    if(status == true)
        IO_RC7_SetHigh();
    else
        IO_RC7_SetLow();    
}
void setD5(bool status)
{
    if(status == true)
        IO_RD5_SetHigh();
    else
        IO_RD5_SetLow();    
}
void setD7(bool status)
{
    if(status == true)
        IO_RD7_SetHigh();
    else
        IO_RD7_SetLow();    
}

/* Lower LEDs*/

void setA2(bool status)
{
    if(status == true)
        IO_RA2_SetHigh();
    else
        IO_RA2_SetLow();    
}
void setA3(bool status)
{
    if(status == true)
        IO_RA3_SetHigh();
    else
        IO_RA3_SetLow();    
}
void setA7(bool status)
{
    if(status == true)
        IO_RA7_SetHigh();
    else
        IO_RA7_SetLow();    
}
void setC0(bool status)
{
    if(status == true)
        IO_RC0_SetHigh();
    else
        IO_RC0_SetLow();    
}
void setD0(bool status)
{
    if(status == true)
        IO_RD0_SetHigh();
    else
        IO_RD0_SetLow();    
}
void setD2(bool status)
{
    if(status == true)
        IO_RD2_SetHigh();
    else
        IO_RD2_SetLow();    
}
void setC4(bool status)
{
    if(status == true)
        IO_RC4_SetHigh();
    else
        IO_RC4_SetLow();    
}
void setC6(bool status)
{
    if(status == true)
        IO_RC6_SetHigh();
    else
        IO_RC6_SetLow();    
}
void setD4(bool status)
{
    if(status == true)
        IO_RD4_SetHigh();
    else
        IO_RD4_SetLow();    
}
void setD6(bool status)
{
    if(status == true)
        IO_RD6_SetHigh();
    else
        IO_RD6_SetLow();    
}