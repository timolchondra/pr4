#include "STOCKS_h.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStocks(Stock stock, int SIZE);
/*
int main(void) {

  int a, b, SIZE = 3179;

  FILE *stocksPTR = fopen("stocks.csv","r");

  if (stocksPTR == NULL) {

    printf("file could not be found");

    return -1;
    
  }

  Stock stockPortfolio = createStock(stocksPTR);
  fclose(stocksPTR);
  
  return 0;
}
*/

Stock createStock(FILE *stocksPTR) {

  Stock stocksPortfolio = malloc(sizeof(struct stocks_type));

  int a, b;
  char *temp = malloc(sizeof(char) * 21);
  fscanf(stocksPTR,"%[^\n]", temp);
  stocksPortfolio -> symbol = malloc(sizeof(char) * 6);

  fscanf(stocksPTR,"%[^,],%lf", stocksPortfolio->symbol, &stocksPortfolio->price);

  //char *temp2 = malloc(sizeof(char) * 21);
  /*
  for (a = 0; a < SIZE; a++) {

    if(a == 0) {
      
      fscanf(stocksPTR,"%[^\n]", temp);
      
      printf("%s",temp);

    } else {
      stocksPortfolio[a - 1].symbol = malloc(sizeof(char) * 6);
      //stocksPortfolio[a - 1].price = malloc(sizeof(double));
      fscanf(stocksPTR,"%[^,],%lf",

	     stocksPortfolio[a - 1].symbol,

	     &stocksPortfolio[a - 1].price);
      
    }
    
  }
*/
  // printStocks(stocksPortfolio);

  //free(stocksPortfolio);
  
}


void printStocks(Stock stocksPortfolio, int SIZE) {

  int a;
  
  for (a = 1; a < 10; a++) {

    printf("%s | %lf\n",

	   stocksPortfolio[a - 1].symbol,

	   stocksPortfolio[a - 1].price);
    
  }

  printf("\n");

}

void destroyPortfolio(Stock stock) {

  free(stock -> symbol);

  //free(stock.price);
  
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

