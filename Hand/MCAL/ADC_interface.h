/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *   FILE NAME	:  UART_interface.h
 *   AUTHOR		:  Yasser Waleed
 *********************************************************************************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../Library/stdtypes.h"
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void ADC_Init();
u8 ADC_Read(u8 channel);
/**********************************************************************************************************************
 *  END OF FILE: ADC_interface.h
 *********************************************************************************************************************/
#endif
