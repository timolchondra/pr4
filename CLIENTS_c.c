#include "CLIENTS_h.h"

void printclients(Client client, int size);

int main() {
  int size = 7;
  FILE *fptr = fopen("clients.txt","r");
  if (fptr == NULL) {
    printf("can't find file");
    return -1;
  }
  Client clientlist = createClients(fptr, size);
  printclients(clientlist,size);
}

Client createClients(FILE *fptr, int size) {
  Client clientlist = malloc(sizeof(struct client_type) * size);
  int i;
  for(i = 0; i < size; i++) {
   // char temp = fgetc(fptr);
    char tempstr[50];
    clientlist[i].id = malloc(sizeof(char) * 100);
    fgets(tempstr, 100, fptr);
    tempstr[strlen(tempstr + 1)] = '\0';
    strcpy(clientlist[i].id, tempstr);
    
    clientlist[i].name = malloc(sizeof(char) * 100);
    fgets(tempstr, 100, fptr);
    tempstr[strlen(tempstr + 1)] = '\0';
    strcpy(clientlist[i].name, tempstr);
    
    clientlist[i].phonenumber = malloc(sizeof(char) * 100);
    fgets(tempstr, 100, fptr);
    tempstr[strlen(tempstr + 1)] = '\0';
    strcpy(clientlist[i].phonenumber, tempstr);
    
    clientlist[i].email = malloc(sizeof(char) * 100);
    fgets(tempstr, 100, fptr);
    tempstr[strlen(tempstr + 1)] = '\0';
    strcpy(clientlist[i].email, tempstr);
    
 /*   while(temp != '\n') { 
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
    strcpy(clientlist[i].email,tempstr); */
  } 

  return clientlist;
}
void destroyClient(Client client) {
  free(client.id);
  free(client.name);
  free(client.phonenumber);
  free(client.email);
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


void printclients(Client clientlist, int size) {
  int i;
  for(i = 0; i < size; i++) {
    printf("%s\n%s\n%s\n%s\n",clientlist[i].id, clientlist[i].name, clientlist[i].phonenumber, clientlist[i].email);
  }  
}
