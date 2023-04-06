#include <stdio.h>
#include <stdlib.h>
#include "../data/data.h"
#include "../utils/print.c"

void deleteWindow(int showStarter)
{
    char input[1000];
    if (showStarter)
        printSubHeading("DELETE ITEM");

    printInfo("\n- Type `exit` to go\n");
    printInfo("- Enter the ID of the book: \n");

    fflush(stdin);
    fgets(input, 1000, stdin);

    if (strcmp(input, "exit\n") == 0)
        return;

    int id = atoi(input);
    Book book = searchBook(id);
    if (book.id == -1)
    {
        printError("Invalid Book ID");
        deleteWindow(1);
        return;
    }
    printBook(book);
    printError("Are you sure you want to delete this book? y/n \n");
    char confirmation;
    scanf("%c", &confirmation);

    if (confirmation == 'y' || confirmation == 'Y')
    {
        deleteBook(id);
        printSuccess("Book deleted Successfully");
    }

    return;
}
