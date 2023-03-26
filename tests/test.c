#include <stdio.h>
#include <stdlib.h>
#include "../src/data/data.h"

int main()
{
    char name[] = "Book Name";
    char author[] = "Aster Joules";

    // Clear if file pre-exist
    remove("books.txt");

    // Add 5 books to the file
    addBook(name, author, name, author, name);
    addBook(name, author, name, author, name);
    addBook(name, author, name, author, name);
    addBook(name, author, name, author, name);
    addBook(name, author, name, author, name);

    // Get the list of books from file
    getBooks();

    return 0;
}
