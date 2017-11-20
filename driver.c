#include "CLIENTS_h.h"
#include "listADTgen.h"
#include "STOCKS_h.h"
///////////////////////////////////////////////////////////////////////////////////////////
///                  __________                   __               __                   ///
///                  \______   \_______  ____    |__| ____   _____/  |_                 ///
///                   |     ___/\_  __ \/  _ \   |  |/ __ \_/ ___\   __\                ///
///                   |    |     |  | \(  <_> )  |  \  ___/\  \___|  |                  ///
///                   |____|     |__|   \____/\__|  |\___  >\___  >__|                  ///
///                                          \______|    \/     \/                      ///
///                            ___________                                              ///
///                            \_   _____/___  __ _________                             ///
///                             |    __)/  _ \|  |  \_  __ \                            ///
///                             |     \(  <_> )  |  /|  | \/                            ///
///                             \___  / \____/|____/ |__|                               ///   
///                                 \/                                                  ///
///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
///   This assignment was done by Timothy Olchondra and Jake McKenzie. Tim ran          ///
///   it on css.gate server under gcc -std=gnu90 -o pr4 pr4.c and Jake ran              ///
///   the file in Ubuntu 16.4 under gcc -std=gnu90 -o pr4 pr4.c . In our assignment     ///
///   we have one set of abstract data types that follow the principle of               ///
///   data hiding along with an ADT that follows the same principles.Specs said         ///
///   that it was allowed but not required to follow data hiding principles but         ///
///   we assume it was good practice to do so so we did it that way.                    ///
///////////////////////////////////////////////////////////////////////////////////////////


int main(void) {

///////////////////////////////////////////////////////////////////////////////////////////
///   Here we take in all the files and open the summary file with which we will        ///
///   write to. The part written below was written by Tim. We are assuming correct      ///
///   inputs but if there is nothing in the file a warning is sent. - Jake              ///
///////////////////////////////////////////////////////////////////////////////////////////  

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

///////////////////////////////////////////////////////////////////////////////////////////
///   Here is where we create the two generic lists for the clients and stocks.         ///
///////////////////////////////////////////////////////////////////////////////////////////  
  
  ListType listClients = create(sizeof(struct client_type),compareID);
  ListType listStocks = create(sizeof(struct stocks_type),compareSymbol);
  
  
  char buffer[100];

  int countline = 0, i, j;
  
///////////////////////////////////////////////////////////////////////////////////////////
///   This is an important step. To enable manpulation of the data structure we         ///
///   needed a way with which to count the lines. Knowing the lines allowed us          ///
///   to take full advantage of the push function provided for us with the assignement. ///
///////////////////////////////////////////////////////////////////////////////////////////

  while(fgets(buffer, 100, clientfptr) != NULL) {

    countline++;

  }

  fclose(clientfptr);

  clientfptr = fopen("clients.txt","r");

///////////////////////////////////////////////////////////////////////////////////////////
///   Here we take advantage of the push function given to us in files.                 ///
///////////////////////////////////////////////////////////////////////////////////////////
  
  for(i = 0; i < countline/4; i++) {

    push(listClients, createClient(clientfptr));

  }
  
  countline = 0;
  
///////////////////////////////////////////////////////////////////////////////////////////
///   Like above but now with stocks we read the lines inorder to use the push function ///
///   provided                                                                          ///
///////////////////////////////////////////////////////////////////////////////////////////
  
  while(fgets(buffer, 100, stockfptr) != NULL) {

    countline++;

  }

  fclose(stockfptr);

  stockfptr = fopen("stocks.csv","r");

  fgets(buffer, 100, stockfptr);

///////////////////////////////////////////////////////////////////////////////////////////
///   Here we take advantage of the push function given to us in files.                 ///
///////////////////////////////////////////////////////////////////////////////////////////

  for(i = 0; i < countline-1; i++) {

    push(listStocks, createStock(stockfptr));

  }
  
  
  printf("%d\n", size_is(listClients));

  printf("%d\n", size_is(listStocks));

  printl(listStocks, printStock);

///////////////////////////////////////////////////////////////////////////////////////////
///   This is where the file is written to. It takes the information gathered above     ///
///   then writes it to summary. This is accomplished by keeping track of our position  ///
///   within the file and our total position.                                           ///
///////////////////////////////////////////////////////////////////////////////////////////

  
  char idmatch[100], stockmatch[100];

  int stockcount, numshares;
  
  for(i = 0; i < size_is(listClients); i++) {

    double total = 0;

    int position = 0;

    fscanf(stockclientfptr,"%s %d", idmatch, &stockcount); 

    printf("%s\n", idmatch);

    printf("%d\n", stockcount);

    position = matchElementString(listClients, getID, idmatch);

    fprintElement(listClients, summary, fprintClient, position); 
    
    for(j = 0; j < stockcount; j++) {

      fscanf(stockclientfptr, "%s %d", stockmatch, &numshares);

      fprintf(summary,"%s,%d,", stockmatch, numshares); 

      position = matchElementString(listStocks, getSymbol, stockmatch);

      fprintElement(listStocks, summary, fprintStockPrice, position);

      total += numshares * getDoublel(listStocks, getPrice, position);   
    } 

    fprintf(summary, "%.2lf,,,\n", total);

  }
  
 
/////////////////////////////////////////////////////////////////////////////////////////// 
///  This destroys all the elements in the clients list.                                /// 
///////////////////////////////////////////////////////////////////////////////////////////
  
  for(i = 0; i < size_is(listClients); i++) {

    destroyElement(listClients, destroyClient, i);

  }

/////////////////////////////////////////////////////////////////////////////////////////// 
///  This destroys all the elements in the stocks list.                                 /// 
///////////////////////////////////////////////////////////////////////////////////////////

  
  for(i = 0; i < size_is(listStocks); i++) {

    destroyElement(listStocks, destroyStock, i);

  }
  

  destroy(listClients);
  destroy(listStocks);
 
  
  fclose(clientfptr);
  fclose(stockfptr);

  return 0;
    
}
