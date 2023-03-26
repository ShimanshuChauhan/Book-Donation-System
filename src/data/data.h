#ifndef DATA_H
#define DATA_H

#include "book.h"

Book *getBooks();
int addBook(char *name, char *author, char *donatedBy, char *phone, char *address);

#endif // DATA_H