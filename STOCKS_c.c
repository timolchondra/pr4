#include "STOCKS_h.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  int SIZE = 3179;

  FILE *stocksPTR = fopen("stocks.csv","r");

  if (stocksPTR == NULL) {
    
    printf("can't find file");

    return -1;

  }
  
  char temp[21];
  fscanf(stocksPTR,"%[^\n]", temp);
  
  Stock stock[2];

  stock[0] = createStock(stocksPTR);
  stock[1] = createStock(stocksPTR);

  
  printStock(stock[0]);
  printStock(stock[1]);
  
  
}

Stock createStock(FILE *stocksPTR) {

  Stock stock = malloc(sizeof(struct stocks_type));
  
  stock -> symbol = malloc(sizeof(char) * 6);

  fscanf(stocksPTR,"%[^,],%lf", stock->symbol, &stock->price);

  return stock;
  
}
void destroyStock(Stock stock) {

  free(stock -> symbol);

  
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

  printf("%s\n%lf\n", stock->symbol,  stock->price);

}

int compareSymbol(Stock stock1, Stock stock2) {

  return strcmp(stock1->symbol,stock2->symbol);

}
