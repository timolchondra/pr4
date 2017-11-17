#include "STOCKS_h.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStocks(struct stocks_type*, int);

int main(void) {

  int a, b, SIZE = 3179;

  //Stock *stocksPortfolio =  calloc(SIZE, sizeof(struct stocks_type));
  
  struct stocks_type stocksPortfolio[SIZE];

  char temp[21];
  
  FILE *stocksPTR = fopen("stocks.csv","r");

  //char *temp = (char *) calloc(21,sizeof(char));
  
  if (stocksPTR == NULL) {

    printf("file could not be found");

    return -1;
    
  }

  //int a, b, SIZE = 3179;

  //char temp[21];

  for (a = 0; a < SIZE; a++) {

    if(a == 0) {

      fscanf(stocksPTR,"%[^\n]", temp);

      //printf("%s",temp);

    } else {

      fscanf(stocksPTR,"%[^,],%lf",

	     stocksPortfolio[a - 1].symbol,

	     &stocksPortfolio[a - 1].price);
      
    }
    
  }
  
  printStocks(stocksPortfolio,SIZE);
  
  fclose(stocksPTR);
  
  return 0;
}

void printStocks(struct stocks_type stocksPortfolio[], int SIZE) {

  int a;
  
  for (a = 1; a < 10; a++) {

    printf("%s | %lf\n",

	   stocksPortfolio[a - 1].symbol,

	   stocksPortfolio[a - 1].price);
    
  }

  printf("\n");

}
