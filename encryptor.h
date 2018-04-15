#ifndef __ENCRIPTER_H__
#define __ENCRIPTER_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  int S[256];
  char * keystream;
  const char * key;
  int i;
  int j;
} encryptor_t;

void encryptor_create(encryptor_t * self, const char * key);
void encryptor_encrypt(encryptor_t * self, char * input, int len);
void encryptor_destroy(encryptor_t * self);

#endif
