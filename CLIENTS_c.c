#include "CLIENTS_h.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printclients(struct client_type clientlist[], int size);
int main() {
  FILE *fptr = fopen("clients.txt","r");
  if(fptr==NULL) {
    printf("file could not be found");
    return -1;
  }
  struct client_type clientlist[7];
  int i = 0,j, size = 7;
  char buff;
  //for(i=0; i < 7;i++) {
   // for(j=0; j < 4; j++) {
     // if(j==0) {
       // fscanf(fptr,"%[^\n]%*c",clientlist[i].id);
      // fgets(clientlist[i].id,100,fptr);
     // }
     // if(j==1) {
     //  fscanf(fptr,"%[^\n]%*c",clientlist[i].name);
     //   fgets(clientlist[i].name,100,fptr);
     // }
     // if(j==2) { 
        //fscanf(fptr,"%[^\n]%*c",clientlist[i].phonenumber);
      //   fgets(clientlist[i].phonenumber,14,fptr);      
     // }
     // if(j==3) {
      //   fgets(clientlist[i].email,100,fptr);
       // fscanf(fptr,"%[^\n]%*c",clientlist[i].email);
        
     // }     
    //}
 // }
 
 // for(i = 0; i < size; i++) {
    j = 0;
    char temp = fgetc(fptr);
    while(temp != '\n') { 
      printf("%c\n",temp);
      clientlist[i].id[j] = temp;
      j++;
      temp = fgetc(fptr);
    }
    clientlist[i].id[j] = '\0';
    printf("%s\n", clientlist[i].id);
    j = 0;
    temp = fgetc(fptr);
    while(temp != '\n') {
      clientlist[i].name[j] = temp;
      j++;
      temp = fgetc(fptr);
    }
    clientlist[i].name[j] = '\0';
     printf("||%s||\n", clientlist[i].name);
    j = 0;
    temp = fgetc(fptr);
    while(temp != '\n') {
      clientlist[i].phonenumber[j] = temp;
      j++;
      temp = fgetc(fptr);
    }
    clientlist[i].phonenumber[j] = '\0';
    j = 0;
    temp = fgetc(fptr);
    while(temp != '\n') {
     clientlist[i].email[j] = temp;
     j++;
     temp = fgetc(fptr);
    }
    clientlist[i].email[j] = '\0';
  
  
//  }
  printf("\n");
  printf("%s\n", clientlist[0].id);
  printf("%s\n", clientlist[0].name);
  printf("%s\n", clientlist[0].phonenumber);
  printf("%s\n", clientlist[0].email);
 
 // printclients(clientlist[], size);
  fclose(fptr);
}

void printclients(struct client_type clientlist[], int size) {
  int i;
  for(i = 0; i < size; i++) {
    printf("%s\n%s\n%s\n%s\n",clientlist[i].id, clientlist[i].name, clientlist[i].phonenumber, clientlist[i].email);
  }  
}
