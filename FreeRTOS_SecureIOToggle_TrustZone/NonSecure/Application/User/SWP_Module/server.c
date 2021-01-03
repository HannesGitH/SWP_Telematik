/*
 * connection.c
 *
 *  Created on: 28.12.2020
 *      Author: F. Pilz
 */

#include "server.h"
//#include "stm32l5xx_nucleo.h"

/* Socket creation according to
 * https://sbop.freertos.org/FreeRTOS-Plus/FreeRTOS_Plus_TCP/TCP_Networking_Tutorial_TCP_Client_and_Server.html*/

int setupConnnection(void){
	struct freertos_sockaddr xClient, xBindAddress;
	Socket_t server, client;				//The Server expects only one Client to connect
	socklen_t socketSize = sizeof(server);
	static const TickType_t rcv_timeo = portMAX_DELAY;
	const BaseType_t backlog = 20;			//Could be set to one, as we only expect one thread to connect

	server = FreeRTOS_socket(FREERTOS_AF_INET, FREERTOS_SOCK_STREAM, FREERTOS_IPPROTO_TCP);
	configASSERT(sever != FREERTOS_INVALID_SOCKET);

	FreeRTOS_setsockopt(server, 0, FREERTOS_SO_RCVTIMEO, &rcv_timeo, sizeof(rcv_timeo));

	xBindAddress.sin_port = (uint16_t) 10000;
	xBindAddress.sin_port = FreeRTOS_htons( xBindAddress.sin_port );

	FreeRTOS_bind(server, &xBindAddress, sizeof(xBindAddress));

	FreeRTOS_listen(server, backlog);
	while(1){
		BSP_LED_Toggle(LED3);
	}
}
