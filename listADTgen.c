#include "listADTgen.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list_type {
  void *data;
  int size;
  int capacity;
  int elementSize;
  int (*comparePtr) (void *d1, void *d2);
};


// returns the pointer to the list; NULL if list not created
ListType create(int elSize, int (*comp) (void *item1, void * item2)) {
  // allocate memory for a structure variable containing all
  // list components
  ListType listptr = malloc(sizeof(struct list_type));
  // if allocation was succesfull
  if (listptr != NULL) {
     listptr->size = 0;
     listptr->capacity = 10;
     listptr->elementSize = elSize;
     listptr->comparePtr = comp;
     //listptr->destroyPtr = destroy;
     // allocate memory for the actual array
     listptr->data = malloc(10*(listptr->elementSize));
     // if array not created, deallocate the list too
     if (listptr->data == NULL) {
       free(listptr);
       listptr = NULL;
     }
  }
  return listptr;
}

void destroy(ListType listptr) {
  free(listptr->data);
  free(listptr);
  listptr = NULL;
}

void printl(ListType listptr, void (*printItem) (void *d)) {
  int i;
  for(i = 0; i < listptr->size; i++) {
    printItem(listptr->data + i * (listptr->elementSize) );
   // printf(" ");
  }
  printf("\n");
}

char* getCharl(ListType listptr, char* (*getString) (void *d), int position) {
  return getString(listptr->data + position * (listptr->elementSize));
}

double getDoublel(ListType listptr, double (*getDouble) (void *d), int position) {
  return getDouble(listptr->data + position * (listptr->elementSize));
}

void destroyElement(ListType listptr, void (*destroy) (void *d), int position) {
  destroy(listptr->data + position * (listptr->elementSize));
}
int size_is(ListType listptr) {
   return listptr->size;
}

int is_empty(ListType listptr) {
   return listptr->size == 0;
}

// assumes list elements were not allocated dynamically
void make_empty(ListType listptr) {
  // if list is larger than 200 elements, create a smaller one
  if (listptr->size > 200)
    listptr->data = realloc(listptr->data, listptr->elementSize * 100);

   listptr->size = 0;
   listptr->capacity = 100;
}
int matchElementString(ListType listptr, void* (*getElementString)(void *Item), char str[]) {
  int position;
  
  for(position = 0; position < listptr->size; position++) {  
  
    if(strcmp(str, getElementString(listptr->data + position * (listptr->elementSize))) == 0) {
      break;
    }    
  }
  if(position >= listptr->size) {
    printf("There was no match\n");
    return -1;
  }
  
  return position;
}

// adds a component to the array, if enough memory available
void push(ListType listptr, void *item) {
  if (listptr->size >= listptr->capacity) {
    void *temp = realloc(listptr->data, listptr->elementSize * (listptr->capacity + 100));
    if (temp != NULL) {
      listptr->capacity += 100;
      listptr->data = temp;
     }
   }
   if (listptr->size < listptr->capacity) {
     memcpy(listptr->data + (listptr->size) * (listptr->elementSize), item, (listptr->elementSize));
     listptr->size++;
   }
}

void fprintElement(ListType listptr, FILE *fptr, void (*fprintItem)(FILE *fptr, void *Item),int position) {
  fprintItem(fptr, (listptr->data + position * (listptr->elementSize)));
}

int is_full(ListType listptr) {
  if (listptr->size >= listptr->capacity) {
      void * temp = malloc(listptr->elementSize* (listptr->capacity + 100));
   if (temp != NULL) {
	free(temp);
	return 0;
   }
   else
     return 1;
   }
   return 0;
}
void delete(ListType listptr, void *item) {

}

