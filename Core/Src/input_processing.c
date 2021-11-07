/*
 * input_processing.c
 *
 *  Created on: Oct 4, 2021
 *      Author: Admin
 */


#include "main.h"
#include "input_reading.h"
#include "display7SEG.h"
#include "led_display.h"

#define DELAY_TIME 20
#define INITIAL_RED_TIME 8
#define INITIAL_YELLOW_TIME 2
#define INITIAL_GREEN_TIME 6

//enum ButtonState { MODE_0 , MODE_1, MODE_2, MODE_3, M1_BTN2, M1_BTN3, M2_BTN2, M2_BTN3} buttonState;

enum ButtonState { MODE_0 , MODE_1, MODE_2, MODE_3, M1_BTN2, M1_BTN3 , M2_BTN2, M2_BTN3, M3_BTN2, M3_BTN3} buttonState;
enum ButtonState buttonState = MODE_0;

int red_time = 11;
int yellow_time = 2;
int green_time = 6;
int count_red = 1;
int count_yellow = 1;
int count_green = 1;

int temp_red = 5;
int temp_yellow = 5;
int temp_green = 5;


int t,i,k,l,j,s,o;

enum ButtonState display_light()
{
	int chuc,donvi,chuc1,donvi1;
	donvi1=l%10;
	chuc1=(l%100)/10;
	donvi=t%10;
	chuc=(t%100)/10;
	int delay_time = 90;

	 for(int i=0;i<delay_time;i++)
	{
		 if(is_button_pressed(0)) return MODE_1;

	  display7SEG(1, chuc);
	  HAL_Delay(1);
	  turn_off_7seg(1);

	  display7SEG(2, donvi);
	  HAL_Delay(1);
	  turn_off_7seg(2);

	  display7SEG(3, chuc1);
	  HAL_Delay(1);
	  turn_off_7seg(3);

	  display7SEG(4, donvi1);
	  HAL_Delay(1);
	  turn_off_7seg(4);

	 }
	 return MODE_0;
}

 enum ButtonState display_led_normal(int tred, int tgreen, int tyellow)
{
		++tred;
		++tgreen;

		while(1){

			if(is_button_pressed(0)) return MODE_1;
			t=tred,l=tgreen,s=tyellow,o=tred;
			for(int k =tred;k>0;k--)
			{
				if(is_button_pressed(0)) return MODE_1;
				t--;
				l--;
				o--;
				if(l<0)
				{
					if(is_button_pressed(0)) return MODE_1;
					l=s;
				}


				if(o<tred-tgreen)
				{
					if(is_button_pressed(0)) return MODE_1;
					HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, GPIO_PIN_SET);



					HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, GPIO_PIN_SET);
				}
				else{
					if(is_button_pressed(0)) return MODE_1;
					HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, GPIO_PIN_SET);



					HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, GPIO_PIN_RESET);
				}
				if(is_button_pressed(0)) return MODE_1;
				display_light();



			}
			break;
		}



		while(1){

			if(is_button_pressed(0)) return MODE_1;
			t=tgreen,l=tred,s=tyellow,o=tred;
			for(int k =tred;k>0;k--)
			{
				if(is_button_pressed(0)) return MODE_1;
				t--;
				l--;
				o--;

				if(t<0)
				{
					if(is_button_pressed(0)) return MODE_1;
					t = s;
				}

				if(o<tred-tgreen)
				{
					if(is_button_pressed(0)) return MODE_1;
					HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, GPIO_PIN_SET);


					HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, GPIO_PIN_SET);
				}
				else{
					if(is_button_pressed(0)) return MODE_1;
					HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, GPIO_PIN_RESET);


					HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, GPIO_PIN_SET);
				}
				if(is_button_pressed(0)) return MODE_1;
				display_light();


			}
			break;
		}

		return MODE_0;
}
 enum ButtonState display_led_red(int time)
 {
	 int flag1 = 0;
	 int flag2 = 0;
	 int chuc;
	 int donvi;
	 int dem;
	 if(flag1==0 && flag2==0)
	 {
		 for(dem=time;dem>=0;dem--)
		 {
	  	      chuc = dem/10;
	  	  	  donvi = dem%10;
			  if(flag1==1 || flag2==1) break;
			  for(int j=0;j<DELAY_TIME;j++)
			  {
				  if(is_button_pressed(0)){
				  	flag1 = 1;
				  	break;
				  }

				  if(is_button_pressed(1)){
				  	flag2 = 1;
				  	break;
				  }
				  	display7SEG(1, 0);
				  	HAL_Delay(1);
				  	turn_off_7seg(1);

				    display7SEG(2, 1);
				  	HAL_Delay(1);
				  	turn_off_7seg(2);

				  	display7SEG(3, chuc);
				  	HAL_Delay(10);
				  	turn_off_7seg(3);

				  	display7SEG(4, donvi);
				  	HAL_Delay(10);
				  	turn_off_7seg(4);
			  }
		 }
	 }
	  HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, GPIO_PIN_RESET);
	  HAL_Delay(20);
	  HAL_GPIO_WritePin(LED2_RED_GPIO_Port, LED2_RED_Pin, GPIO_PIN_RESET);
	  HAL_Delay(50);

	  	if(flag1==0&&flag2==0) return MODE_1;
		else if(flag1==1 && flag2==0) return MODE_2;
		else if(flag1==0 && flag2==1) return  M1_BTN2;
		else return MODE_0;
 }
 enum ButtonState display_counter_red()
 {

		 int chuc;
		 int donvi;

		 int dem;


			 dem = count_red;
			 chuc = dem/10;
			 donvi = dem%10;

			  for(int j=0;j<8;j++)
			  {
				  	display7SEG(1, 0);
				  	HAL_Delay(1);
				  	turn_off_7seg(1);

				    display7SEG(2, 1);
				  	HAL_Delay(1);
				  	turn_off_7seg(2);

				  	display7SEG(3, chuc);
				  	HAL_Delay(10);
				  	turn_off_7seg(3);

				  	display7SEG(4, donvi);
				  	HAL_Delay(10);
				  	turn_off_7seg(4);
			  }
		if(is_button_pressed(2)) return M1_BTN3;
		if(is_button_pressed(1)){
			count_red++;
			if(count_red>99) count_red = 0;
		}

		 return M1_BTN2;


 }
 enum ButtonState display_led_yellow(int time)
  {
 	 int flag1 = 0;
 	 int flag2 = 0;
 	 int chuc;
 	 int donvi;
 	 int dem;
 	 if(flag1==0 && flag2==0)
 	 {
 		 for(dem=time;dem>=0;dem--)
 		 {
 	  	      chuc = dem/10;
 	  	  	  donvi = dem%10;
 			  if(flag1==1 || flag2==1) break;
 			  for(int j=0;j<DELAY_TIME;j++)
 			  {
 				  if(is_button_pressed(0)){
 				  	flag1 = 1;
 				  	break;
 				  }

 				  if(is_button_pressed(1)){
 				  	flag2 = 1;
 				  	break;
 				  }
 				  	display7SEG(1, 0);
 				  	HAL_Delay(1);
 				  	turn_off_7seg(1);

 				    display7SEG(2, 2);
 				  	HAL_Delay(1);
 				  	turn_off_7seg(2);

 				  	display7SEG(3, chuc);
 				  	HAL_Delay(10);
 				  	turn_off_7seg(3);

 				  	display7SEG(4, donvi);
 				  	HAL_Delay(10);
 				  	turn_off_7seg(4);
 			  }
 		 }
 	 }
 	  HAL_GPIO_WritePin(LED1_YELLOW_GPIO_Port, LED1_YELLOW_Pin, GPIO_PIN_RESET);
 	  HAL_Delay(20);
 	  HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, GPIO_PIN_RESET);
 	  HAL_Delay(50);

 	  	if(flag1==0&&flag2==0) return MODE_2;
 		else if(flag1==1 && flag2==0) return MODE_3;
 		else if(flag1==0 && flag2==1) return  M2_BTN2;
 		else return MODE_0;
  }
 enum ButtonState display_counter_yellow()
 {

		 int chuc;
		 int donvi;

		 int dem;


			 dem = count_yellow;
			 chuc = dem/10;
			 donvi = dem%10;

			  for(int j=0;j<8;j++)
			  {
				  	display7SEG(1, 0);
				  	HAL_Delay(1);
				  	turn_off_7seg(1);

				    display7SEG(2, 2);
				  	HAL_Delay(1);
				  	turn_off_7seg(2);

				  	display7SEG(3, chuc);
				  	HAL_Delay(10);
				  	turn_off_7seg(3);

				  	display7SEG(4, donvi);
				  	HAL_Delay(10);
				  	turn_off_7seg(4);
			  }
		if(is_button_pressed(2)) return M2_BTN3;
		if(is_button_pressed(1)){
			count_yellow++;
			if(count_yellow>99) count_yellow = 0;
		}

		 return M2_BTN2;
}
 enum ButtonState display_led_green(int time)
   {
  	 int flag1 = 0;
  	 int flag2 = 0;
  	 int chuc;
  	 int donvi;
  	 int dem;
  	 if(flag1==0 && flag2==0)
  	 {
  		 for(dem=time;dem>=0;dem--)
  		 {
  	  	      chuc = dem/10;
  	  	  	  donvi = dem%10;
  			  if(flag1==1 || flag2==1) break;
  			  for(int j=0;j<DELAY_TIME;j++)
  			  {
  				  if(is_button_pressed(0)){
  				  	flag1 = 1;
  				  	break;
  				  }

  				  if(is_button_pressed(1)){
  				  	flag2 = 1;
  				  	break;
  				  }
  				  	display7SEG(1, 0);
  				  	HAL_Delay(1);
  				  	turn_off_7seg(1);

  				    display7SEG(2, 3);
  				  	HAL_Delay(1);
  				  	turn_off_7seg(2);

  				  	display7SEG(3, chuc);
  				  	HAL_Delay(10);
  				  	turn_off_7seg(3);

  				  	display7SEG(4, donvi);
  				  	HAL_Delay(10);
  				  	turn_off_7seg(4);
  			  }
  		 }
  	 }
  	  HAL_GPIO_WritePin(LED1_GREEN_GPIO_Port, LED1_GREEN_Pin, GPIO_PIN_RESET);
  	  HAL_Delay(20);
  	  HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, GPIO_PIN_RESET);
  	  HAL_Delay(50);

  	  	if(flag1==0&&flag2==0) return MODE_3;
  		else if(flag1==1 && flag2==0) return MODE_0;
  		else if(flag1==0 && flag2==1) return  M3_BTN2;
  		else return MODE_0;
   }
 enum ButtonState display_counter_green()
  {

 		 int chuc;
 		 int donvi;

 		 int dem;


 			 dem = count_green;
 			 chuc = dem/10;
 			 donvi = dem%10;

 			  for(int j=0;j<8;j++)
 			  {
 				  	display7SEG(1, 0);
 				  	HAL_Delay(1);
 				  	turn_off_7seg(1);

 				    display7SEG(2, 3);
 				  	HAL_Delay(1);
 				  	turn_off_7seg(2);

 				  	display7SEG(3, chuc);
 				  	HAL_Delay(10);
 				  	turn_off_7seg(3);

 				  	display7SEG(4, donvi);
 				  	HAL_Delay(10);
 				  	turn_off_7seg(4);
 			  }
 		if(is_button_pressed(2)) return M3_BTN3;
 		if(is_button_pressed(1)){
 			count_green++;
 			if(count_green>99) count_green = 0;
 		}

 		 return M3_BTN2;
 }
 void fsm_for_input_processing (){

	switch(buttonState)
		  {
		  case MODE_0:
			  turn_off_all_led();
			  display_mode(0);
			  yellow_time = red_time - green_time;
			  buttonState = display_led_normal(red_time,green_time, yellow_time);
			  HAL_Delay(30);
			 break;


		//====== MODE 1 ===== //

		  case MODE_1:

			  turn_off_all_led();
			  display_mode(1);
			  buttonState = display_led_red(5);
			 break;
		  case M1_BTN2:
			  turn_off_all_led();
			  buttonState = display_counter_red();
			  break;

		  case M1_BTN3:
			  turn_off_all_led();
			  if(is_button_pressed(2))
			  {
				  red_time = count_red;
				  buttonState = MODE_1;
			  }
			  else{
				  buttonState = M1_BTN3;
			  }
			  break;



		//====== MODE 2 ===== //

		  case MODE_2:

			  turn_off_all_led();
			  display_mode(2);
			  buttonState = display_led_yellow(5);
			  break;
		  case M2_BTN2:
			  turn_off_all_led();
			  buttonState = display_counter_yellow();
			  break;

		  case M2_BTN3:
			  turn_off_all_led();
			  if(is_button_pressed(2))
			  {
				  yellow_time = count_yellow;
				  buttonState = MODE_2;
			  }
			  else{
				  buttonState = M2_BTN3;
			  }
			  break;





		//====== MODE 3 ===== //

		  case MODE_3:
			  turn_off_all_led();
			  display_mode(3);
			  buttonState = display_led_green(5);
			  break;


		  case M3_BTN2:
			  turn_off_all_led();
			  buttonState = display_counter_green();
			  break;

		  case M3_BTN3:
			  turn_off_all_led();
			  if(is_button_pressed(2))
			  {
				  green_time = count_green;
				  buttonState = MODE_3;
			  }
			  else{
				  buttonState = M3_BTN3;
			  }
			  break;


		  }

}




