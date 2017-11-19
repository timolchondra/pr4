#include "STOCKS_h.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stock createStock(FILE *stocksPTR) {

  Stock stock = malloc(sizeof(struct stocks_type));
  
  stock -> symbol = malloc(sizeof(char) * 6);

  fscanf(stocksPTR,"%[^ ,] ,%lf", stock->symbol, &stock->price);

  return stock;
  
}
void destroyStock(Stock stock) {

  free(stock -> symbol);
  //free(stock);
}

char* getSymbol(Stock stock) {

  return stock -> symbol;
  
}

double getPrice(Stock stock) {

  return stock -> price;
  
}

void setSymbol(Stock stock, char* newSymbol) {

  strcpy(stock -> symbol, newSymbol);
  
}

void setPrice(Stock stock, double newPrice) {

  stock -> price = newPrice;
  
}

void printStock(Stock stock) {

  printf("%s %.2lf\n", stock->symbol,  stock->price);

}

int compareSymbol(Stock stock1, Stock stock2) {

  return strcmp(stock1->symbol,stock2->symbol);

}

void fprintStockPrice(FILE *fptr, Stock stock) {

  fprintf(fptr, "%.2lf,,", stock->price); 
  
}