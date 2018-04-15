#ifndef __ENCRIPTER_H__
#define __ENCRIPTER_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define S_SIZE 256

typedef struct {
  int S[S_SIZE];
  char * keystream;
  const char * key;
  int i;
  int j;
} encryptor_t;

/*precondiciones: recibe por parametro un puntero de tipo struct encryptor, 
y una clave
postcondiciones: Se inicializará el encriptador para esa clave*/
void encryptor_create(encryptor_t * self, const char * key);

/*precondiciones: recibe por parametro un puntero de tipo struct socket, 
un mensaje y una longitud.
postcondiciones: encriptara o desencriptara 
(dependiendo la condicion inicial del input), 
desde el comienzo del array apuntado hasta la longitud indicada. 
El resultado se sobreescribe.*/
void encryptor_encrypt(encryptor_t * self, char * input, int len);
void encryptor_destroy(encryptor_t * self);

#endif
