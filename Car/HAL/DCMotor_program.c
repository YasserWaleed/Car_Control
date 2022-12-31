/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------**
 *    FILE NAME			:  DCMotor_program.c
 *   BRIEF DESCRIPTION	:  Implementation of DCMotor_interface.h
 *   AUTHOR				:  Yasser Waleed
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <avr/io.h>
#include "DCMotor_interface.h"
#include "../MCAL/PWM_interface.h"
#include "../MCAL/DIO_interface.h"
#include "../Library/stdtypes.h"
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void DCMotor_Init()
{
	DIO_InitPort(A, OUTPUT);
}
void DCMotor_SetRotation(Motor_t Motor, s8 Speed)
{
	if (Motor == R_MOTOR)
	{
		if (Speed > 0)
		{
			DIO_WritePin(A, P1, HIGH);
			DIO_WritePin(A, P2, LOW);
			PWM_DutyCycle(TIMER0, Speed);
		}
		if (Speed < 0)
		{
			DIO_WritePin(A, P1, LOW);
			DIO_WritePin(A, P2, HIGH);
			PWM_DutyCycle(TIMER0, -Speed);
		}
		if (Speed == 0)
		{
			DIO_WritePin(A, P1, LOW);
			DIO_WritePin(A, P2, LOW);
		}
	}
	if (Motor == L_MOTOR)
	{
		if (Speed > 0)
		{
			DIO_WritePin(A, P3, HIGH);
			DIO_WritePin(A, P4, LOW);
			PWM_DutyCycle(TIMER2, Speed);
		}
		if (Speed < 0)
		{
			DIO_WritePin(A, P3, LOW);
			DIO_WritePin(A, P4, HIGH);
			PWM_DutyCycle(TIMER2, -Speed);
		}
		if (Speed == 0)
		{
			DIO_WritePin(A, P3, LOW);
			DIO_WritePin(A, P4, LOW);
		}
	}
}
/**********************************************************************************************************************
 *  END OF FILE: DCMotor_program.c
 *********************************************************************************************************************/
