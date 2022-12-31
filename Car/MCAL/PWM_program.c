/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------**
 *    FILE NAME			:  PWM_program.c
 *   BRIEF DESCRIPTION	:  Implementation of PWM_interface.h
 *   AUTHOR				:  Yasser Waleed
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <avr/io.h>
#include "PWM_interface.h"
#include "../Library/stdtypes.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define TIMER_MAX_COUNT 255
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void PWM_DutyCycle(Timer_t Timer, u8 Duty_Cycle_Percentage)
{
	//SET UPPER LIMIT AS 100 AND LOWER LIMIT AS 0
	if (Duty_Cycle_Percentage > 100){Duty_Cycle_Percentage = 100;}
	if (Duty_Cycle_Percentage < 0){Duty_Cycle_Percentage =   0;}

	if (Timer == TIMER0)
	{
		TCNT0 = 0; //Set Timer Initial value
		OCR0  = (((u16)Duty_Cycle_Percentage * TIMER_MAX_COUNT)/100);
		DDRB  = DDRB | (1<<PB3); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.
		TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
	}
	if (Timer == TIMER2)
	{
		TCNT2 = 0; //Set Timer Initial value
		OCR2  = (((u16)Duty_Cycle_Percentage * TIMER_MAX_COUNT)/100);
		DDRD  = DDRD | (1<<PD7); //set PD7/OC2 as output pin --> pin where the PWM signal is generated from MC.
		TCCR2 = (1<<WGM20) | (1<<WGM21) | (1<<COM21) | (1<<CS21);
	}
}
/**********************************************************************************************************************
 *  END OF FILE: PWM_program.c
 *********************************************************************************************************************/
