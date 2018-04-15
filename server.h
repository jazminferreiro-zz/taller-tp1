#ifndef __SERVER_H__
#define __SERVER_H__

#define _POSIX_C_SOURCE 200112L

#include "socket.h"
#include "encryptor.h"

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

/*precondiciones: recibe  un puerto y una clave, 
postcondiciones: tratará de levantarse un puerto en ese server */
int server(const int port, const char * key);

/*precondiciones: recibe  un socket, un desencriptador 
y el nombre de un archiv. 
postcondiciones: tratará de recibir los mensajes del cliente conectado
para desencriptarlos y guardarlos en el archivo que 
se llamará como se especifico por parámetros*/
int server_accept_client(
	socket_t * skt, encryptor_t * server_decryptor, FILE * file);

#endif
