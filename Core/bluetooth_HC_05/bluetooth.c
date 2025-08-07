/*
 * bluetooth.c
 *
 *  Created on: Aug 7, 2025
 *      Author: werlley
 */

#include "bluetooth.h"

setupBluetooth ble;

char buff[BUFFER_SIZE];

void bluetooth_setup(void){
	ble.handler = &huart1;
	ble.GPIOx = enable_cmd_AT_GPIO_Port;
	ble.GPIO_pin = enable_cmd_AT_Pin;
	ble.mode = NORMAL;
}

int UART_Print_Transmit(char* fmt, ...){
    va_list args;

    va_start(args, fmt);
    int size = vsnprintf(buff, sizeof(buff), fmt, args);
    va_end(args);

    if(size <= 0){
    	errno = ENOMEM;
    	return -1;
    }
    HAL_StatusTypeDef hal_test = HAL_UART_Transmit(ble.handler, (uint8_t*)buff, (uint16_t)size, HAL_MAX_DELAY);
    if(hal_test != HAL_OK){
    	errno = hal_test = HAL_TIMEOUT? ETIMEDOUT:EBUSY;
    	return -1;
    }

    comandos_at_response((uint8_t *)buff, BUFFER_SIZE, TIMEOUT);

    if(strstr(buff, "OK") != NULL){

    }

    return 0;
}


void comandos_at_init(void){
	UART_Print_Transmit(COMANDO_AT_INIT);
}

void comandos_at_set_name(const char *name){
	UART_Print_Transmit("%s%s\r\n", COMANDO_AT_SET_NAME, name);
}

void comandos_at_response(uint8_t *buffer, uint32_t length, uint32_t timeout){
	HAL_UART_Receive(ble.handler, (uint8_t*)buffer, (uint16_t)length, timeout);
	buff[length - 1] = '\0';
}

void comandos_at_setBaudrate(uint16_t *baud){
	UART_Print_Transmit("%s=%u\r\n", COMANDO_AT_SET_NAME, baud);
}

void bluetooth_enable_cmd_at(void){
	HAL_GPIO_WritePin(ble.GPIOx, ble.GPIO_pin, GPIO_PIN_SET);
}

void bluetooth_disable_cmd_at(void){
	HAL_GPIO_WritePin(ble.GPIOx, ble.GPIO_pin, GPIO_PIN_RESET);
}

void bluetooth_init(void){
	bluetooth_setup();
	bluetooth_enable_cmd_at();
}


