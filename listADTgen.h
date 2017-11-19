#ifndef LISTADT_H
#define LISTADT_H
#include <stdio.h>

typedef struct list_type *ListType;

ListType create(int elSize, int (*compare) (void *item1, void *item2));
void destroy(ListType listP);
void make_empty(ListType listP);
int is_empty(ListType listP);
int is_full(ListType listP);
int size_is(ListType listP);
void push(ListType listP, void *item);
void delete(ListType listP, void* item);
void printl(ListType listP, void (*printItem) (void *item));
char* getCharl(ListType listptr, char* (*getString) (void *d),int position);
double getDoublel(ListType listptr, double (*getDouble) (void *d), int position);
void destroyElement(ListType listptr, void (*destroy) (void *d), int poisition);
void fprintElement(ListType listptr, FILE *fptr, void (*fprintItem)(FILE *fptr, void *Item),int position);
int matchElementString(ListType listptr, void* (*getElementString)(void *Item), char str[]);


#endif



