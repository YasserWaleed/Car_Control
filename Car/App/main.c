/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*
 *   FILE NAME			:  main.c
 *   BRIEF DESCRIPTION	:  Receive command from Hand Module, and control the car accordingly
 *   AUTHOR				:  Yasser Waleed
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <avr/io.h>             // registers
#include <stdio.h>              // sprintf()
#include <util/delay.h>         // _delay_xx()
#include "../HAL/LCD_interface.h"
#include "../HAL/DCMotor_interface.h"
#include "../MCAL/UART_interface.h"
#include "../MCAL/PWM_interface.h"
#include "../Library/stdtypes.h"
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
s8 R_Speed, L_Speed;
u8 Message, display[16], R_Finger, L_Finger;
/**********************************************************************************************************************
 *  MAIN FUNCTIONS
 *********************************************************************************************************************/
int main(void)
{
	DCMotor_Init();
	UART_Init(9600);
	lcd_init(LCD_DISP_ON);
	lcd_clrscr();
	_delay_ms(100);

	while (1)
	{
		//Receive Message, get the values for R_Finger and L_Finger
		Message = UART_ReceiveChar();
		R_Finger = Message % 10;
		L_Finger = (Message - R_Finger) / 10;

		//Set Speed of the motors, negative value means backward
		if 		(R_Finger == 1)	{ R_Speed = -4; DCMotor_SetRotation(R_MOTOR, -100);}//backward , speed 100%
		else if (R_Finger == 2) { R_Speed = -3; DCMotor_SetRotation(R_MOTOR, -75 );}//backward , speed 75%
		else if (R_Finger == 3) { R_Speed = -2; DCMotor_SetRotation(R_MOTOR, -50 );}//backward , speed 50%
		else if (R_Finger == 4) { R_Speed = -1; DCMotor_SetRotation(R_MOTOR, -25 );}//backward , speed 25%
		else if (R_Finger == 5) { R_Speed =  0; DCMotor_SetRotation(R_MOTOR,  0  );}//neutral  , speed 0
		else if (R_Finger == 6) { R_Speed =  1; DCMotor_SetRotation(R_MOTOR,  25 );}//forward  , speed 25%
		else if (R_Finger == 7) { R_Speed =  2; DCMotor_SetRotation(R_MOTOR,  50 );}//forward  , speed 50%
		else if (R_Finger == 8) { R_Speed =  3; DCMotor_SetRotation(R_MOTOR,  75 );}//forward  , speed 75%
		else if (R_Finger == 9)	{ R_Speed =  4; DCMotor_SetRotation(R_MOTOR,  100);}//forward  , speed 100%

		if 		(L_Finger == 1)	{ L_Speed = -4; DCMotor_SetRotation(L_MOTOR, -100);}//backward , speed 100%
		else if (L_Finger == 2)	{ L_Speed = -3; DCMotor_SetRotation(L_MOTOR, -75 );}//backward , speed 75%
		else if (L_Finger == 3) { L_Speed = -2; DCMotor_SetRotation(L_MOTOR, -50 );}//backward , speed 50%
		else if (L_Finger == 4) { L_Speed = -1; DCMotor_SetRotation(L_MOTOR, -25 );}//backward , speed 25%
		else if (L_Finger == 5) { L_Speed =  0; DCMotor_SetRotation(L_MOTOR,  0  );}//neutral  , speed 0
		else if (L_Finger == 6) { L_Speed =  1; DCMotor_SetRotation(L_MOTOR,  25 );}//forward  , speed 25%
		else if (L_Finger == 7) { L_Speed =  2; DCMotor_SetRotation(L_MOTOR,  50 );}//forward  , speed 50%
		else if (L_Finger == 8) { L_Speed =  3; DCMotor_SetRotation(L_MOTOR,  75 );}//forward  , speed 75%
		else if (L_Finger == 9)	{ L_Speed =  4; DCMotor_SetRotation(L_MOTOR,  100);}//forward  , speed 100%

		//	Display current speed on LCD
		sprintf(display, "R:%d ", R_Speed);
		lcd_gotoxy(0,0);
		lcd_puts(display);
		sprintf(display, "L:%d ", L_Speed);
		lcd_gotoxy(0,1);
		lcd_puts(display);
		_delay_ms(50);
	}
}
