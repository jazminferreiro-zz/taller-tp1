#ifndef __SOCKET_H__
#define __SOCKET_H__

#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>
#include <string.h>

typedef struct {
  int socket;
  const char * host_name;
  unsigned short port;
  bool is_connected;
} socket_t;


/*precondiciones: recibe por parametro un puntero de tipo struct socket, 
un puntero a host y un puerto en formato numerico positivo
postcondiciones: inicializara el socket*/
int socket_create(socket_t *self, const char * host_name, unsigned short port);

/*precondiciones: recibe por parametro un puntero de tipo struct socket
postcondiciones: lo destruye*/
int socket_destroy(socket_t *self);

/*precondiciones: recibe por parametro un puntero de tipo struct socket
postcondiciones: trata de conectarse al puerto y hostname indicados al crear*/
int socket_connect(socket_t *self);

/*precondiciones: recibe por parametro un puntero de tipo struct socket, 
un buffer y la longitud del mensaje que se quiere enviar
postcondiciones: intentará enviar el mensaje contenido en el buffer*/
int socket_send_message(socket_t *self, const char* buffer, size_t length);

/*precondiciones: recibe por parametro un puntero de tipo struct socket, 
un buffer y la longitud del mensaje que se quiere recibir
postcondiciones: intentará recibir tantos bytes como los pasados por parametro
en legth, y los guardara en el buffer, si el socket se cierra guardara hasta la cantidad de bytes que le lleguen*/
int socket_recive_message(socket_t *self, char* buffer, size_t length);
int socket_bind_and_listen(socket_t *self);
int socket_accept(socket_t *self, socket_t* accepted_socket);

#endif
 
