/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*
 *   FILE NAME			:  main.c
 *   BRIEF DESCRIPTION	:  Read ADC input, Send a command to the Car Module accordingly
 *   AUTHOR				:  Yasser Waleed
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include "../MCAL/UART_interface.h"
#include "../MCAL/ADC_interface.h"
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
	u8 message;
	u16 left_finger, right_finger;
/**********************************************************************************************************************
 *  MAIN FUNCTION
 *********************************************************************************************************************/
int main(void)
{
	ADC_Init();
	UART_init(9600);

	_delay_ms(800);
	while (1)
	{
		//	(1) Reading ADC input, scaled by 0.4 to fit range of 100 degrees
		left_finger = ADC_Read(0)*0.4;
		right_finger = ADC_Read(1)*0.4;

		//	(2a) The first digit represents the right finger
		if 			 (right_finger <= 10)				  {message += 1;}
		else if (10 < right_finger && right_finger <= 20) {message += 2;}
		else if (20 < right_finger && right_finger <= 30) {message += 3;}
		else if (30 < right_finger && right_finger <= 40) {message += 4;}
		else if (40 < right_finger && right_finger <= 60) {message += 5;}
		else if (60 < right_finger && right_finger <= 70) {message += 6;}
		else if (70 < right_finger && right_finger <= 80) {message += 7;}
		else if (80 < right_finger && right_finger <= 90) {message += 8;}
		else if (90 < right_finger)		 				  {message += 9;}

		//	(2b) The second digit represents the left finger
		if 			 (left_finger <= 10) 				{message += 10;}
		else if (10 < left_finger && left_finger <= 20) {message += 20;}
		else if (20 < left_finger && left_finger <= 30) {message += 30;}
		else if (30 < left_finger && left_finger <= 40) {message += 40;}
		else if (40 < left_finger && left_finger <= 60) {message += 50;}
		else if (60 < left_finger && left_finger <= 70) {message += 60;}
		else if (70 < left_finger && left_finger <= 80) {message += 70;}
		else if (80 < left_finger && left_finger <= 90) {message += 80;}
		else if (90 < left_finger)		 				{message += 90;}

		UART_TransmitChar(message); //	(3) Send Message
		message = 0;
		_delay_ms(100);
	}
}
