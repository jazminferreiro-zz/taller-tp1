#include "encryptor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define S_SIZE 256

void encryptor_ksa(encryptor_t * self);
void encryptor_prga(encryptor_t * self, int len);
void encryptor_swap_S(encryptor_t * self, int i, int j);
void stderr_keystream_hexa_uppercase(encryptor_t *self , int len);
void stdin_input_hexa_lowercase(char * input, int len);




//key-scheduling
void encryptor_ksa(encryptor_t * self){
  for (int i=0; i < S_SIZE; i++){
    self->S[i] = i;
  }
  int keyLen = strlen(self->key);

  int j = 0;
  for (int i=0; i < S_SIZE; i++){
    j = (j+ self->S[i] + self->key[i % keyLen]) %S_SIZE;
    encryptor_swap_S(self,i,j);
  }
}

//programacion pseudo-aleatoria
void encryptor_prga(encryptor_t * self, int len){
  int  k;
  for (int index =0; index <len; index++){
    self->i = (self->i +1) % S_SIZE;
    self->j = (self->j +self->S[self->i]) % S_SIZE;
    encryptor_swap_S(self, self->i, self->j);

    k = self->S[(self->S[self->i]+self->S[self->j]) % S_SIZE];
    self->keystream[index] = k;
  }
}

void encryptor_swap_S(encryptor_t * self, int i, int j){
  int aux = self->S[i];
  self->S[i]= self->S[j];
  self->S[j] = aux; 
}



void stderr_keystream_hexa_upperrcase(encryptor_t *self , int len){
  for (int i=0; i < len; i++){
    fprintf(stderr, "%02hhX", self->keystream[i]);
  }
}

void stdin_input_hexa_lowercase(char * input, int len){
  for (int i=0; i < len; i++){
    printf("%02hhx", input[i]);
  }
}

void encryptor_encrypt(encryptor_t * self, char * input, int len){
  self-> keystream = (char *)malloc(sizeof(char)*len);
  encryptor_prga(self, len);
  for (int i = 0; i < len; i++){
    input[i] = input[i] ^ self->keystream[i];
  }
  stdin_input_hexa_lowercase(input, len);
  stderr_keystream_hexa_upperrcase(self,len);
  free(self->keystream);
}

void encryptor_create(encryptor_t * self, const char * key){
  self->key = key;
  self-> i = 0;
  self-> j = 0;
  encryptor_ksa(self);
}

void encryptor_destroy(encryptor_t * self){
}

