#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"

int addBook(char *name, char *author, char *donatedBy, char *phone, char *address)
{
    FILE *fp;
    fp = fopen("books.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file!");
        return 0;
    }

    // write each book to file as text
    int i;
    fprintf(fp, "%s\t%s\t%s\t%s\t%s\n", name, author, donatedBy, phone, address);

    // close the file
    fclose(fp);
    return 1;
}
Book *getBooks()
{
    FILE *fp;
    fp = fopen("books.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file!");
        return NULL;
    }

    // count the number of lines in the file
    int count = 0;
    char line[1000];
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        count++;
    }
    rewind(fp);

    // allocate the books array on the heap
    Book *books = malloc(count * sizeof(Book));
    if (books == NULL)
    {
        printf("Error allocating memory!");
        return NULL;
    }

    // read the book data from the file
    int i;
    for (i = 0; i < count; i++)
    {

        fgets(line, sizeof(line), fp);
        char *name = strtok(line, "\t");
        char *author = strtok(NULL, "\t");
        char *donatedBy = strtok(NULL, "\t");
        char *phone = strtok(NULL, "\t");
        char *address = strtok(NULL, "\n");

        if (name == NULL || author == NULL)
        {
            printf("Error reading book data!");
            return NULL;
        }
        strcpy(books[i].name, name);
        strcpy(books[i].author, author);
        strcpy(books[i].address, address);
        strcpy(books[i].donatedBy, donatedBy);
        strcpy(books[i].phone, phone);
    }

    // close the file
    fclose(fp);

    // print the books
    for (i = 0; i < count; i++)
    {
        printf("Book: %s\t Author: %s\t DonatedBy: %s\t Phone: %s\t Address: %s\n", books[i].name, books[i].author, books[i].donatedBy, books[i].phone, books[i].address);
    }

    return books;
}