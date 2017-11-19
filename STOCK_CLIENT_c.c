#include "STOCK_CLIENT_h.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  FILE *stocksClientsPTR = fopen("stock_client.txt","r");

  if (stocksClientsPTR == NULL) {
    
    printf("can't find file");

    return -1;

  }
  
  StockClient stockClient[2];

  stockClient[0] = createStockClient(stocksClientsPTR);
  stockClient[1] = createStockClient(stocksClientsPTR);
  
  printStockClient(stockClient[0]);
  printStockClient(stockClient[1]);
}

StockClient createStockClient(FILE *stocksClientsPTR) {

  int a ,b;

  StockClient stockClient = malloc(sizeof(struct stocks_client_type));

  stockClient -> ID = malloc(sizeof(char) * 5);

  fscanf(stocksClientsPTR,"%s %d", stockClient->ID, &stockClient->amountOfUniqueStocks);

  b = stockClient->amountOfUniqueStocks;
  for (a = 0;a < b; a++) {

    stockClient -> symbol = malloc(sizeof(char) * 6);

    //stockClient -> amountOfUniqueShares = malloc(sizeof(int));
    
    fscanf(stocksClientsPTR,"%s %d", stockClient->symbol, &stockClient->amountOfUniqueShares);
    
  }

  return stockClient;
  
}
void destroyStockClient(StockClient stockClient) {

  free(stockClient -> symbol);
  
}

char* getSymbol(StockClient stockClient) {

  return stockClient -> symbol;
  
}

char* getID(StockClient stockClient) {

  return stockClient -> ID;
  
}

int getAmountOfUniqueStocks(StockClient stockClient) {

  return stockClient -> amountOfUniqueStocks;
  
}

int getAmountOfUniqueShares(StockClient stockClient) {

  return stockClient -> amountOfUniqueShares;
  
}

void setSymbol(StockClient stockClient, char* newSymbol) {

  strcpy(stockClient -> symbol, newSymbol);
  
}

void setID(StockClient stockClient, char* newID) {

  strcpy(stockClient -> ID, newID);
  
}

void setAmountOfUniqueStocks(StockClient stockClient, int newAmountOfUniqueStocks) {

  stockClient -> amountOfUniqueStocks = newAmountOfUniqueStocks;
  
}

void setAmountOfUniqueShares(StockClient stockClient, int newAmountOfUniqueShares) {

  stockClient -> amountOfUniqueShares = newAmountOfUniqueShares;
  
}

void printStockClient(StockClient stockClient) {

  int a;
  
  printf("%s %d\n", stockClient -> ID, stockClient -> amountOfUniqueStocks);

  for (a = 0; a < stockClient -> amountOfUniqueStocks;a++) {

    printf("%s %d\n",stockClient->symbol, stockClient->amountOfUniqueShares);
    
  }
  
}
