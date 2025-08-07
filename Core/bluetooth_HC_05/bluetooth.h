/*
 * bluetooth.h
 *
 *  Created on: Aug 7, 2025
 *      Author: werlley
 */

#ifndef BLUETOOTH_HC_05_BLUETOOTH_H_
#define BLUETOOTH_HC_05_BLUETOOTH_H_

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>

#define TIMEOUT 100
#define BUFFER_SIZE 128

#define COMANDO_AT_INIT 		"AT"
#define COMANDO_AT_RESET 		"AT+RESET"
#define COMANDO_AT_VERSION 		"AT+VERSION"
#define COMANDO_AT_NAME 		"AT+NAME"
#define COMANDO_AT_SET_NAME 	"AT+NAME=%S"
#define COMANDO_AT_ADDR 		"AT+ADDR"
#define COMANDO_AT_BAUDRATE 	"AT+BAUD"
#define COMANDO_AT_SET_BAUDRATE "AT+BAUD=%S"
#define COMANDO_AT_PSWD 		"AT+PSWD"
#define COMANDO_AT_SET_PSWD		"AT+PSWD=%S"
#define COMANDO_AT_PIN 			"AT+PIN"
#define COMANDO_AT_SET_PIN		"AT+PIN=%S"

typedef enum{
	NORMAL=0,
	N_BLE
}listBLE;

typedef struct{
	UART_HandleTypeDef 	*handler;
	GPIO_TypeDef 		*GPIOx;
	uint16_t 			GPIO_pin;
	listBLE 			mode;
}setupBluetooth;

extern UART_HandleTypeDef huart1;

extern void bluetooth_setup(void);

extern int UART_Print_Transmit(char* fmt, ...);
extern void comandos_at_init(void);
extern void comandos_at_set_name(const char *name);
extern void comandos_at_response(uint8_t *buffer, uint32_t length, uint32_t timeout);
extern void comandos_at_setBaudrate(uint16_t *baud);

extern void bluetooth_enable_cmd_at(void);
extern void bluetooth_disable_cmd_at(void);
extern void bluetooth_init(void);

#endif /* BLUETOOTH_HC_05_BLUETOOTH_H_ */
