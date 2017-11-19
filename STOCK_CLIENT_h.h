#ifndef STOCK_CLIENT_H
#define STOCK_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stocks_client_type {
  char *ID;
  char *symbol;
  int amountOfUniqueStocks;
  int amountOfUniqueShares;
};

typedef  struct stocks_client_type *  StockClient;

StockClient createStockClient(FILE *file);

char* getID(StockClient stockClient);

char* getSymbol(StockClient stockClient);

int getAmountOfUniqueStocks(StockClient stockClient);

int getAmountOfUniqueShares(StockClient stockClient);

void destroyStockClient(StockClient stockClient);
void setID(StockClient stockClient, char* newID);
void setSymbol(StockClient stockClient, char* newSymbol);
void setAmountOfUniqueStocks(StockClient stockClient, int newAmountOfUniqueStocks);
void setAmountOfUniqueShares(StockClient stockClient, int newAmountOfUniqueStocks);
void printStockClient(StockClient stockClient);

#endif
