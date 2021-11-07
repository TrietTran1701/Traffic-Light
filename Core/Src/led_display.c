///*
// * led_display.c
// *
// *  Created on: Oct 4, 2021
// *      Author: Admin
// */
//
//
#include "main.h"
#include "led_display.h"
#include "display7SEG.h"
#define DELAY_TIME 50




int t,i,k,l,j,s,o;


void turn_off_all_led()
{
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, GPIO_PIN_SET);
}



