/*
 * mainpp.cpp
 *
 *  Created on: Jul 23, 2023
 *      Author: paul3
 */
#include "mainpp.h"
#include "pusher.h"
#include "chassis_DCmotor.h"
#include "stm32h7xx_hal.h"
#include "script.h"
#include "ros.h"
#include "geometry_msgs/Twist.h"
#include "STM32Hardware.h"

extern SCRIPT script_a;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim23;

int aaaaa = 0;

void setup(void);
void main_function(){

	PUSHER pusher_A;
	PUSHER pusher_B;
//	PUSHER pusher_C;
//	PUSHER pusher_D;
//	SCRIPT script_a;
	setup();
	stm_setup();
	script_a.scriptrun = 0;

	while(1){
		Vy = 10;
		HAL_Delay(10000);
		Vy = 0.0;
		HAL_Delay(100000);
		pusher_A.distence();
		pusher_B.distence();
		script();
		loop();

	}
}
void stm_setup(void){
	HAL_TIM_Base_Start_IT(&htim1);
	HAL_TIM_Base_Start_IT(&htim8);
	HAL_TIM_Base_Start_IT(&htim23);//main Timer
	DC_motor_init();
}


void callback(const geometry_msgs::Twist &msg)
{
	aaaaa ++;
   Vx = msg.linear.x;
   Vy = msg.linear.y;
   W = msg.angular.z;
}

ros::NodeHandle nh;
ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", callback);


/* UART Communication */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 57600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart){
    if(huart == &huart1){
    // set velocity 0 before uart reinitialization
		HAL_UART_DeInit(&huart1);
		MX_USART1_UART_Init();
		nh.getHardware()->init();
    }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    nh.getHardware()->flush();
}

void setup(void)
{
    nh.initNode();
    nh.subscribe(sub);
}
void loop(void)
{
//	aaaaa++;
    nh.spinOnce();
}
