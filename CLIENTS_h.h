#ifndef CLIENTS_H
#define CLIENTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct client_type {
  char *id;
  char *name;
  char *phonenumber;
  char *email;  
};

typedef struct client_type *Client;
Client createClient (FILE *file);
void destroyClient(Client client);
char* getID(Client client);
char* getName(Client client);
char* getNumber(Client client);
char* getEmail(Client client);
void setID(Client client, char* newid);
void setName(Client client, char* newname);
void setNumber(Client client, char* newnumber);
void setEmail(Client client, char* newemail);
int compareID(Client client1, Client client2);



#endif


