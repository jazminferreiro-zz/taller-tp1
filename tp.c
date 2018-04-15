#define _POSIX_C_SOURCE 200112L
#include "client.h"
#include "server.h"

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define SUCCESS 0
#define ERROR 1

#define MIN_ARGUMENTS_EXPECTED 4
#define CLIENT_ARGUMENTS_EXPECTED 6
#define TRUE 0

#define CLIENT_IP 2
#define CLIENT_PORT 3
#define CLIENT_KEY 4
#define CLIENT_FILE_NAME 5

#define SERVER_PORT 2
#define SERVER_KEY 3

int main(int argc, char *argv[]){
   if (argc < MIN_ARGUMENTS_EXPECTED){
    printf("Parametros incorrectos. \n");
    return ERROR;
  }
  int is_client = strcmp(argv[1],"client"); 
  if (is_client == TRUE){
    if (argc < CLIENT_ARGUMENTS_EXPECTED){
      printf("Parametros incorrectos. \n");
      return ERROR;
    }
    return client(argv[CLIENT_IP],atoi(argv[CLIENT_PORT]),argv[CLIENT_KEY],argv[CLIENT_FILE_NAME]);
  }
  return server(atoi(argv[SERVER_PORT]),argv[SERVER_KEY]);
}






