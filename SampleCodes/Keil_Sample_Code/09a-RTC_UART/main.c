/***************************************************************************************************
                                   ExploreEmbedded
****************************************************************************************************
 * File:   main.c
 * Version: 16.0
 * Author: ExploreEmbedded
 * Website: http://www.exploreembedded.com/wiki
 * Description: This file contains the program to read & write date&time from internal RTC 
 *              Date and time is set only once in the beginning after that it is continously read and transmitted on UART

This code has been developed and tested on ExploreEmbedded boards.  
We strongly believe that the library works on any of development boards for respective controllers. 
Check this link http://www.exploreembedded.com/wiki for awesome tutorials on 8051,PIC,AVR,ARM,Robotics,RTOS,IOT.
ExploreEmbedded invests substantial time and effort developing open source HW and SW tools, to support consider 
buying the ExploreEmbedded boards.
 
The ExploreEmbedded libraries and examples are licensed under the terms of the new-bsd license(two-clause bsd license).
See also: http://www.opensource.org/licenses/bsd-license.php

EXPLOREEMBEDDED DISCLAIMS ANY KIND OF HARDWARE FAILURE RESULTING OUT OF USAGE OF LIBRARIES, DIRECTLY OR
INDIRECTLY. FILES MAY BE SUBJECT TO CHANGE WITHOUT PRIOR NOTICE. THE REVISION HISTORY CONTAINS THE INFORMATION 
RELATED TO UPDATES.
 

Permission to use, copy, modify, and distribute this software and its documentation for any purpose
and without fee is hereby granted, provided that this copyright notices appear in all copies 
and that both those copyright notices and this permission notice appear in supporting documentation.
**************************************************************************************************/

#include "rtc.h"
#include "uart.h"
#include "stdutils.h"
#include "systemInit.h"


int main() 
{
    rtc_t rtc;
    SystemInit();
    UART0_Init(9600);  

    RTC_Init();
    rtc.hour = 10; //  10:40:20 am
    rtc.min =  40;
    rtc.sec =  0;

    rtc.date = 1; //1st Jan 2016
    rtc.month = 1;
    rtc.year = 2016;
    rtc.weekDay = 5; // Friday: 5th day of week considering monday as first day.   


    /*##### Set the time and Date only once. Once the Time and Date is set, comment these lines
         and reflash the code. Else the time will be set every time the controller is reset*/
    RTC_SetDateTime(&rtc);  //  10:40:20 am, 1st Jan 2016


    /* Display the Time and Date continuously */
    while(1)
    {
        RTC_GetDateTime(&rtc);
        UART0_Printf("\n\rtime:%2d:%2d:%2d  Date:%2d/%2d/%4d",(uint16_t)rtc.hour,(uint16_t)rtc.min,(uint16_t)rtc.sec,(uint16_t)rtc.date,(uint16_t)rtc.month,(uint16_t)rtc.year);
    }	      
}

