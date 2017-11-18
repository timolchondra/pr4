#ifndef STOCKS_H
#define STOCKS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stocks_type {
  char *symbol;
  double price;
};
//Stock create (void);
typedef  struct stocks_type *  Stock;
Stock createPortfolio(FILE *file,int SIZE);
void destroyPortfolio(Stock stock);
char* getSymbol(Stock stock);
double getPrice(Stock stock);
void setSymbol(Stock stock, char* newSymbol);
void setPrice(Stock stock, double newPrice);



//*char getSymbol(Stock stock.symbol);
//double getPrice(Stock stock.price);
//char* getSymbol(void);
//double getPrice(void);

#endif
