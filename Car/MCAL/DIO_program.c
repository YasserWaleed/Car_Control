/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*
 *   FILE NAME			:  DIO_program.c
 *   BRIEF DESCRIPTION	:  Implementation of DIO_interface.h
 *   AUTHOR				:  Yasser Waleed
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <avr/io.h>
#include "../MCAL/DIO_interface.h"
#include "../Library/stdtypes.h"
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void DIO_InitPin		(Port_t Port, Pin_t Pin, Direction_t Direction)
{
	if(Direction == OUTPUT)
	{
		switch(Port)
		{
			case A	:	DDRA |= (1<<Pin); break;
			case B	:	DDRB |= (1<<Pin); break;
			case C	:	DDRC |= (1<<Pin); break;
			case D	:	DDRD |= (1<<Pin); break;
		}
	}
	if(Direction == INPUT)
	{
		switch(Port)
		{
			case A	:	DDRA &=~ (1<<Pin); break;
			case B	:	DDRB &=~ (1<<Pin); break;
			case C	:	DDRC &=~ (1<<Pin); break;
			case D	:	DDRD &=~ (1<<Pin); break;
		}
	}
}

void DIO_InitPort	(Port_t Port, Direction_t Direction)
{
	if(Direction == OUTPUT)
	{
		switch(Port)
		{
			case A	:	DDRA = 0xFF; break;
			case B	:	DDRB = 0xFF; break;
			case C	:	DDRC = 0xFF; break;
			case D	:	DDRD = 0xFF; break;
		}
	}
	if(Direction == INPUT)
	{
		switch(Port)
		{
			case A	:	DDRA = 0; break;
			case B	:	DDRB = 0; break;
			case C	:	DDRC = 0; break;
			case D	:	DDRD = 0; break;
		}
	}
}

void DIO_WritePin	(Port_t Port, Pin_t Pin, u8 Value)
{
	if(Value == HIGH)
	{
		switch(Port)
		{
			case A	:	PORTA |= (1<<Pin) ; break;
			case B	:	PORTB |= (1<<Pin) ; break;
			case C	:	PORTC |= (1<<Pin) ; break;
			case D	:	PORTD |= (1<<Pin) ; break;
		}
	}
	if(Value == LOW)
	{
		switch(Port)
		{
			case A	:	PORTA &=~ (1<<Pin) ; break;
			case B	:	PORTB &=~ (1<<Pin) ; break;
			case C	:	PORTC &=~ (1<<Pin) ; break;
			case D	:	PORTD &=~ (1<<Pin) ; break;
		}
	}
}

void DIO_WritePort	(Port_t Port, u8 Value)
{
	switch(Port)
	{
		case A	:	PORTA = Value ; break;
		case B	:	PORTB = Value ; break;
		case C	:	PORTC = Value ; break;
		case D	:	PORTD = Value ; break;
	}
}
/**********************************************************************************************************************
 *  END OF FILE: DIO_program.c
 *********************************************************************************************************************/
