#include "CLIENTS_h.h"

void printclient(Client client);

int main() {
  int size = 7;
  FILE *fptr = fopen("clients.txt","r");
  if (fptr == NULL) {
    printf("can't find file");
    return -1;
  }
  Client clientlist[2];
  clientlist[0] = createClient(fptr);
  clientlist[1] = createClient(fptr);
  
  printclient(clientlist[0]);
  printclient(clientlist[1]);
  
  
}

Client createClient(FILE *fptr) {
    Client client = malloc(sizeof(struct client_type));
    char tempstr[50];
    client->id = malloc(sizeof(char) * 100);
    fgets(tempstr, 100, fptr);
    tempstr[strlen(tempstr + 1)] = '\0';
    strcpy(client->id, tempstr);
    
    client->name = malloc(sizeof(char) * 100);
    fgets(tempstr, 100, fptr);
    tempstr[strlen(tempstr + 1)] = '\0';
    strcpy(client->name, tempstr);
    
    client->phonenumber = malloc(sizeof(char) * 100);
    fgets(tempstr, 100, fptr);
    tempstr[strlen(tempstr + 1)] = '\0';
    strcpy(client->phonenumber, tempstr);
    
    client->email = malloc(sizeof(char) * 100);
    fgets(tempstr, 100, fptr);
    tempstr[strlen(tempstr + 1)] = '\0';
    strcpy(client->email, tempstr);
    
  return client;
}
void destroyClient(Client client) {
  free(client->id);
  free(client->name);
  free(client->phonenumber);
  free(client->email);
  free(client);
}

char* getID(Client client) {
  return client->id;
}
char* getName(Client client) {
  return client->name;
}
char* getNumber(Client client) {
  return client->phonenumber;
}
char* getEmail(Client client) {
  return client->email;
}
void setID(Client client, char* newid) {
  strcpy(client->id, newid);  
}
void setName(Client client, char* newname) {
  strcpy(client->name, newname);
}
void setNumber(Client client, char* newnumber) {
  strcpy(client->phonenumber, newnumber); 
}
void setEmail(Client client, char* newemail) {
  strcpy(client->email, newemail);
}
int compareID(Client client1, Client client2) {
  return strcmp(client1->id,client2->id);
}

void printclient(Client client) {
  printf("%s\n%s\n%s\n%s\n",client->id, client->name, client->phonenumber, client->email);
}
