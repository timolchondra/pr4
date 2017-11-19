#ifndef STOCKS_H
#define STOCKS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stocks_type {
  char *symbol;
  double price;
};

typedef  struct stocks_type *  Stock;

Stock createStock(FILE *file);

char* getSymbol(Stock stock);

double getPrice(Stock stock);

void destroyStock(Stock stock);
void setSymbol(Stock stock, char* newSymbol);
void setPrice(Stock stock, double newPrice);
void printStock(Stock stock);
int compareSymbol(Stock stock1, Stock stock2);
void fprintStockPrice(FILE *fptr, Stock stock);

#endif