#ifndef DATA_H
#define DATA_H

#include "book.h"

Book *getBooks();
int addBook(char *name, char *author, char *donatedBy, char *phone, char *address);
void deleteBook(int id);
void writeCounter(int counter);
int readCounter();
Book searchBook(int id);
Book searchBookByName(char *name);
void updateBook(int id, char *name, char *author, char *donatedBy, char *phone, char *address);
void printBook(Book book);
Book getBookFromLine(char *line);

#endif // DATA_H