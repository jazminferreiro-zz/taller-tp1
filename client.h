#ifndef __CLIENT_H__
#define __CLIENT_H__

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


/*precondiciones: recibe por parametro una ip, un puerto y una clave, 
y el nombre de un archivo 
postcondiciones: tratará de conectarse a esa ip con ese puerto y 
abrir el archivo para lectura y crear un encriptador con la
clave especificada */
int client(const char * ip, const int port, const char * key, //
	const char * file_name);

/*precondiciones: recibe por parametro un socket y un encriptador
postcondiciones: tratará de conectarse a través de ese socket
para mandar el contenido del archivo encriptado con  el encriptador en cuestion*/
int client_send_file_to_server(socket_t * skt,encryptor_t * client_encryptor,//
	FILE * file, int file_len);

#endif
