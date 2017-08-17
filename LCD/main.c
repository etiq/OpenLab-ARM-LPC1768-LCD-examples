/*
 * File name            : main.c
 * Compiler             : MDK-Lite
 * IDE                  : Keil uVision V5
 * Author               : Etiq Technologies
 * Processor            : LPC1768
 * Created on           : June 17, 2017, 9:44 AM
 * Description          : LCD Main Program
 */


#include <lpc17xx.h>
#include "delay.h"
#include "lcd.h"

int main()
{
	SystemInit();                         //Clock and PLL configuration

	INIT_PORTS();													//Sets the direction and initializes the lcd module
		
	while(1){
//Test sending characters
		SEND_CMD(0x80);	
		SEND_CHAR_DATA('T');		
		SEND_CHAR_DATA('E');		
		SEND_CHAR_DATA('S');		
		SEND_CHAR_DATA('T');		
		SEND_CMD(0xC0);	
//Test sending strings
		SEND_STRING_DATA("Etiq");		
		SEND_CMD(0xC9);	
		SEND_STRING_DATA("Tech");		
		delay_ms(1000);
		SEND_CMD(0x01);
	}
}