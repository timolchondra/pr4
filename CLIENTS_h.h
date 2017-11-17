#ifndef CLIENTS_H
#define CLIENTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct client_type {
  char id[100];
  char name[100];
  char phonenumber[100];
  char email[100];  
};

typedef struct client_type *Client;
Client createClients (FILE *file, int size);
void destroyClients(Client client);
char* getID(Client client);
char* getName(Client client);
char* getNumber(Client client);
char* getEmail(Client client);
void setID(Client client);
void setName(Client client);
void setNumber(Client client);
void setEmail(Client client);



#endif


