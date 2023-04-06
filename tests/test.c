#include <stdio.h>
#include <stdlib.h>
#include "../src/data/data.h"
#include "../src/utils/print.c"

int main()
{
    printHeading("Running Test");
    char name[] = "bookName";
    char author[] = "author";
    char donatedBy[] = "donatedBy";
    char phone[] = "phone";
    char address[] = "address";

    // Clear if file pre-exist
    remove("books.txt");
    printSubHeading("Testing: Add Book");

    int counter = readCounter();
    // Add 5 books to the file
    addBook("Book No 1", author, donatedBy, phone, address);
    addBook("Book 2", author, donatedBy, phone, address);
    addBook("Book 3", author, donatedBy, phone, address);
    addBook("Book 4", author, donatedBy, phone, address);
    addBook("Book 5", author, donatedBy, phone, address);

    if (counter + 5 == readCounter())
    {
        printSuccess("Added Books Successfully");
    }

    // Get the list of books from file
    printSubHeading("Testing: Get Books");
    getBooks();

    int tempId = readCounter() - 4;

    // Search for a book by ID
    printSubHeading("Testing: Search Book by ID");
    printf("Searching book with id: %d \n", tempId);
    Book book = searchBook(tempId);
    printf("Book Found: %d %s \n\n", book.id, book.name);

    // Search for a book by name
    printSubHeading("Testing: Search Book by name");
    printf("Searching book with name: %d \n", "Book No 1");
    book = searchBookByName("Book No 1");
    printf("Book Found: %d %s \n\n", book.id, book.name);

    // Update the data of a book
    printSubHeading("Testing: Update Book");
    printf("Updating Data of book with id: %d \n", tempId);
    updateBook(tempId, "New Book", author, donatedBy, phone, address);
    book = searchBook(tempId);
    printf("Updated Book Found: %d %s \n\n", book.id, book.name);

    // Delete a book from file
    printSubHeading("Testing: Delete Book");
    printf("Remove book with id: %d \n", tempId);
    deleteBook(tempId);
    book = searchBook(tempId);
    if (book.id == -1)
    {
        printSuccess("Deleted Book Successfully");
    }

    return 0;
}
