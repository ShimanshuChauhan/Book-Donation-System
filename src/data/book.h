#ifndef BOOK_H
#define BOOK_H

typedef struct
{
    int id;
    char name[256];
    char author[256];
    char donatedBy[100];
    char phone[100];
    char address[100];
} Book;

#endif