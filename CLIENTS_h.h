#ifndef CLIENTS_H
#define CLIENTS_H

struct client_type {
  char id[5];
  char name[50];
  char phonenumber[12];
  char email[50];  
};

typedef  struct client_type *  Client;
Client create (void);
void getID(Client client);
void getName(Client client);
void getNumber(Client client);
void getEmail(Client client);


#endif


