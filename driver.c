#include "CLIENTS_h.h"
#include "listADTgen.h"
#include "STOCKS_h.h"

int main() {
  FILE *clientfptr = fopen("clients.txt","r");
  FILE *stockfptr = fopen("stocks.csv", "r");
  FILE *stockclientfptr = fopen("stock_client.txt","r");
  FILE *summary = fopen("summary.csv", "w");
  
  if(clientfptr == NULL) {
    printf("Could not find client file");
    return -1;
  }
  if(stockfptr == NULL) {
    printf("Could not find stock file");
    return -1;
  }
  if(stockclientfptr == NULL) {
    printf("Could not find stock_client file");
    return -1;
  } 
  
  ListType listClients = create(sizeof(struct client_type),compareID);
  ListType listStocks = create(sizeof(struct stocks_type),compareSymbol);
  
  
 // printf("%d", sizeof(struct client_type));
  char buffer[100];
  int countline = 0;
  int i = 0;
  
  while(fgets(buffer, 100, clientfptr) != NULL) {
    countline++;
  }
 // printf("%d\n", countline);
  fclose(clientfptr);
  clientfptr = fopen("clients.txt","r");
  for(i = 0; i < countline/4; i++) {
    push(listClients, createClient(clientfptr));
  }
  
  countline = 0;
  while(fgets(buffer, 100, stockfptr) != NULL) {
    countline++;
  }
//  printf("%d\n", countline);
  fclose(stockfptr);
  stockfptr = fopen("stocks.csv","r");
  fscanf(stockfptr,"%[^\n]", buffer);
  for(i = 0; i < countline-1; i++) {
    push(listStocks, createStock(stockfptr));
  }
  
  
  printf("%d\n", size_is(listClients));
  printf("%d\n", size_is(listStocks));
  
  
//  int position = 3;
  //printf("%s\n", getCharl(listClients, getName, position));
  //printf("%.2lf\n", getDoublel(listStocks, getPrice, position));
  //printl(listClients, printclient);
  //printl(listStocks, printStock);
  
  
  char idmatch[100];
  int stockcount;
  char stockmatch[100];
  int numshares;
  
  //while(true){}
  fscanf(stockclientfptr,"%s %d", idmatch, &stockcount); 
 /* if(idmatch==NULL) {
  break;
  } */
  printf("%s\n", idmatch);
  printf("%d\n", stockcount);
  int position = 0;
  //search for client with same id
  printl(listClients, printclient);
  position = matchElementString(listClients, getID, idmatch);
  printf("%d\n", position);
  position = 6;
  fprintElement(listClients, summary, fprintClient, position); 
  //print info
  /*for(i = 0; i < stockcount; i++) {
    int total;
    fscanf("%[^ ], %d", stockmatch, numshares);
    //search for stock to get price of stock
    //multiply numshares with price of stock
    //add to total
    //print info
  } */
  
  
 
 
 
  
  for(i = 0; i < size_is(listClients); i++) {
    destroyElement(listClients, destroyClient, i);

  }
 // printf("%d\n", size_is(listClients));
  for(i = 0; i < size_is(listStocks); i++) {
    destroyElement(listStocks, destroyStock, i);

  }
  
 // printf("%d\n", size_is(listStocks));
 
  //make_empty(listClients);
  printf("%d\n", size_is(listClients));
//  make_empty(listStocks);
   printf("%d\n", size_is(listStocks));
  destroy(listClients);
  destroy(listStocks);
 
  
  fclose(clientfptr);
  fclose(stockfptr);
  return 0;
    
}
