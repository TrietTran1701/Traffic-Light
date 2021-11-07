/*
 * display7SEG.c
 *
 *  Created on: Nov 2, 2021
 *      Author: Admin
 */


#include "main.h"
#include "display7SEG.h"

#include "main.h"
#include "display7SEG.h"


void turn_off_7seg(int disp_no)
{
	if(disp_no==1){
		 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
	}

	else if(disp_no==2)
	{
		 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
	}
	else if(disp_no==3)
	{
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
	}
	else{
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
	}
}
void display7SEG(unsigned int disp_no, int var1)
{
	unsigned char disp_arr[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	unsigned char bit_var, var2;

	if(disp_no==1) // turn on first 7segled
	{
	    HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);

	}
	else if(disp_no==2) // turn on second 7segled
	{
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);


	}
	else if(disp_no==3)
	{
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);

	}

	else if(disp_no==4)
	{
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
	}


	var2 = disp_arr[var1];
	bit_var = var2 & 0x01;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, bit_var);

	bit_var=(var2>>1)& 0x01;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, bit_var);

	bit_var=(var2>>2)& 0x01;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, bit_var);

	bit_var=(var2>>3)& 0x01;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, bit_var);

	bit_var=(var2>>4)& 0x01;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, bit_var);

	bit_var=(var2>>5)& 0x01;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, bit_var);

	bit_var=(var2>>6)& 0x01;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, bit_var);

	bit_var=(var2>>7)& 0x01;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, bit_var);
}

void display_mode(int mode)
{
	  for(int i=0;i<40;i++)
	  {
		  display7SEG(1, 0);
		  HAL_Delay(1);
		  turn_off_7seg(1);

		  display7SEG(2, mode);
		  HAL_Delay(1);
		  turn_off_7seg(2);
	  }


}
