#include "CLIENTS_h.h"

void printclients(Client client, int size);

Client createClients(FILE *fptr, int size) {
  Client clientlist = malloc(sizeof(struct client_type) * size);
  int i,j;
  for(i = 0; i < size; i++) {
    j = 0;
    char temp = fgetc(fptr);
    char tempstr[50];
    while(temp != '\n') { 
      tempstr[j] = temp;
      j++;
      temp = fgetc(fptr);
    }
    tempstr[j] = '\0';
    strcpy(clientlist[i].id,tempstr);
    j = 0;
    temp = fgetc(fptr);
    while(temp != '\n') {
      tempstr[j] = temp;
      j++;
      temp = fgetc(fptr);
    }
     tempstr[j] = '\0';
    strcpy(clientlist[i].name,tempstr);
    j = 0;
    temp = fgetc(fptr);
    while(temp != '\n') {
      tempstr[j] = temp;
      j++;
      temp = fgetc(fptr);
    }
    tempstr[j] = '\0';
    j = 0;
    strcpy(clientlist[i].phonenumber,tempstr);
    temp = fgetc(fptr);
    
    while(temp != '\n') {
      tempstr[j] = temp;
      j++;
      temp = fgetc(fptr);
    }
    tempstr[j] = '\0';
    strcpy(clientlist[i].email,tempstr);
  }

  return clientlist;
}
void destroyClients(Client client) {
  free(client);
}
char* getID(Client client) {
  char* str = malloc(sizeof(char) * (strlen(client->id) + 1));
  strcpy(str,client->id);
  return str;
}
char* getName(Client client) {
  char* str = malloc(sizeof(char) * (strlen(client->name) + 1));
  strcpy(str,client->name);
  return str;
}
char* getNumber(Client client) {
  char* str = malloc(sizeof(char) * (strlen(client->number) + 1));
  strcpy(str,client->number);
  return str;
}
char* getEmail(Client client) {
  char* str = malloc(sizeof(char) * (strlen(client->email) + 1));
  strcpy(str,client->email);
  return str;
}


void printclients(Client clientlist, int size) {
  int i;
  for(i = 0; i < size; i++) {
    printf("%s\n%s\n%s\n%s\n",clientlist[i].id, clientlist[i].name, clientlist[i].phonenumber, clientlist[i].email);
  }  
}
