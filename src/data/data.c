#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"
// #include "../utils/print.c"

#define MAX_LINE_LENGTH 1024

int readCounter()
{
    int counter = 0;
    FILE *fp = fopen("counter.txt", "r");
    if (fp != NULL)
    {
        fscanf(fp, "%d", &counter);
        fclose(fp);
    }
    return counter;
}

void writeCounter(int counter)
{
    FILE *fp = fopen("counter.txt", "w");
    if (fp != NULL)
    {
        fprintf(fp, "%d", counter);
        fclose(fp);
    }
}

int addBook(char *name, char *author, char *donatedBy, char *phone, char *address)
{

    int counter = readCounter();
    // printf("Counter Received: %d\n", counter);
    char id[MAX_LINE_LENGTH];
    sprintf(id, "%d", counter);
    // printf("ID Generated: %s\n", id);
    FILE *fp;
    fp = fopen("books.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file!");
        return 0;
    }

    // write each book to file as text
    int i;
    fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\n", id, name, author, donatedBy, phone, address);
    writeCounter(counter + 1);

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
    char line[MAX_LINE_LENGTH];
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
        char *counter = strtok(line, "\t");
        char *name = strtok(NULL, "\t");
        char *author = strtok(NULL, "\t");
        char *donatedBy = strtok(NULL, "\t");
        char *phone = strtok(NULL, "\t");
        char *address = strtok(NULL, "\n");

        if (name == NULL || author == NULL)
        {
            printf("Error reading book data!");
            return NULL;
        }
        // strcpy(books[i].id, atoi(counter));
        books[i].id = atoi(counter);
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
        printf("ID:%d\t Book: %s\t Author: %s\t DonatedBy: %s\t Phone: %s\t Address: %s\n", books[i].id, books[i].name, books[i].author, books[i].donatedBy, books[i].phone, books[i].address);
    }

    return books;
}

void deleteBook(int id)
{
    // open the books file for reading
    FILE *fp = fopen("books.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    // open a temporary file for writing
    FILE *tmp = fopen("temp.txt", "w");
    if (tmp == NULL)
    {
        printf("Error opening temporary file!\n");
        fclose(fp);
        return;
    }

    // read each line from the books file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char tempLine[MAX_LINE_LENGTH];
        strcpy(tempLine, line);
        // parse the line to extract the ID
        char *counter = strtok(line, "\t");
        int book_id = atoi(counter);

        // if the ID does not match the book_id write it to file
        if (book_id != id)
        {
            fputs(tempLine, tmp);
        }
    }

    // Cleaning Up
    fclose(fp);
    fclose(tmp);

    // Remove the original books file
    remove("books.txt");

    // Rename the temporary file to the original books file
    rename("temp.txt", "books.txt");
}

Book getBookFromLine(char *line)
{
    Book book = {0};

    char *token = strtok(line, "\t"); // get the first token
    book.id = atoi(token);

    token = strtok(NULL, "\t"); // get the next token
    strcpy(book.name, token);

    token = strtok(NULL, "\t"); // get the next token
    strcpy(book.author, token);

    token = strtok(NULL, "\t"); // get the next token
    strcpy(book.donatedBy, token);

    token = strtok(NULL, "\t"); // get the next token
    strcpy(book.phone, token);

    token = strtok(NULL, "\t"); // get the next token
    strcpy(book.address, token);

    return book;
}

Book searchBook(int id)
{
    FILE *input_file = fopen("books.txt", "r");
    if (input_file == NULL)
    {
        perror("Failed to open input file");
        Book not_found = {0}; // return a zeroed-out Book struct
        return not_found;
    }

    char line[MAX_LINE_LENGTH];
    Book found_book = {-1}; // initialize to all zeros
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL)
    {
        char *id_str = strtok(line, "\t");
        int book_id = atoi(id_str);
        if (book_id == id)
        {
            found_book.id = book_id;
            strncpy(found_book.name, strtok(NULL, "\t"), sizeof(found_book.name));
            strncpy(found_book.author, strtok(NULL, "\t"), sizeof(found_book.author));
            strncpy(found_book.donatedBy, strtok(NULL, "\t"), sizeof(found_book.donatedBy));
            strncpy(found_book.phone, strtok(NULL, "\t"), sizeof(found_book.phone));
            strncpy(found_book.address, strtok(NULL, "\t"), sizeof(found_book.address));
            break;
        }
    }

    fclose(input_file);

    return found_book;
}

void updateBook(int id, char *name, char *author, char *donatedBy, char *phone, char *address)
{
    FILE *input_file = fopen("books.txt", "r");
    if (input_file == NULL)
    {
        perror("Failed to open input file");
        return;
    }

    FILE *temp_file = tmpfile();
    if (temp_file == NULL)
    {
        perror("Failed to create temporary file");
        fclose(input_file);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL)
    {
        char tempLine[MAX_LINE_LENGTH];
        strcpy(tempLine, line);
        char *id_str = strtok(line, "\t");
        int book_id = atoi(id_str);
        if (book_id == id)
        {
            fprintf(temp_file, "%d\t%s\t%s\t%s\t%s\t%s\n", id, name, author, donatedBy, phone, address);
        }
        else
        {
            fputs(tempLine, temp_file);
        }
    }

    fclose(input_file);

    FILE *output_file = fopen("books.txt", "w");
    if (output_file == NULL)
    {
        perror("Failed to open output file");
        fclose(temp_file);
        return;
    }

    rewind(temp_file);
    while (fgets(line, MAX_LINE_LENGTH, temp_file) != NULL)
    {
        fputs(line, output_file);
    }

    fclose(temp_file);
    fclose(output_file);
}

Book searchBookByName(char *name)
{
    FILE *input_file = fopen("books.txt", "r");
    if (input_file == NULL)
    {
        printf("Error: Could not open file '%s' for reading.\n", "books.txt");
        Book empty_book = {0};
        empty_book.id = -1;
        return empty_book;
    }

    char line[1024];
    while (fgets(line, 1024, input_file))
    {
        Book book = getBookFromLine(line);
        if (strcmp(book.name, name) == 0)
        {
            fclose(input_file);
            return book;
        }
    }

    fclose(input_file);
    Book empty_book = {0};
    empty_book.id = -1;
    return empty_book;
}

void printBook(Book book)
{
    printf("ID:%d\tName:%s\tAuthor:%s\tDonatedBy:%s\tPhone:%s\tAddress:%s\n", book.id, book.name, book.author, book.donatedBy, book.phone, book.address);
}
