#ifndef STOCKS_H
#define STOCKS_H

struct stocks_type {
  char symbol[6];
  double price;
};

typedef  struct stocks_type *  Stock;
Stock create (void);
void getSymbol(Stock stock);
void getPrice(Stock stock);


#endif
