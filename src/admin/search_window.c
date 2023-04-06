#include <stdio.h>
#include <stdlib.h>
#include "../data/data.h"
#include "../utils/print.c"

void searchByName()
{
    char input[1000];
    printInfo("- Enter the name of the book: \n");

    fflush(stdin);
    fgets(input, 1000, stdin);

    input[strcspn(input, "\n")] = '\0';

    Book book = searchBookByName(input);
    if (book.id == -1)
    {
        printError("\nNo book exists with this name\n");
        return;
    }
    printSuccess("Book Found\n");
    printBook(book);
}

void searchById()
{
    char input[1000];
    printInfo("- Enter the ID of the book: \n");

    fflush(stdin);
    fgets(input, 1000, stdin);

    if (strcmp(input, "exit\n") == 0)
        return;

    int id = atoi(input);
    Book book = searchBook(id);
    if (book.id == -1)
    {
        printError("\nInvalid Book ID\n");
        return;
    }
    printSuccess("Book Found\n");
    printBook(book);
}
void searchWindow(int showStarter)
{
    char input[1000];
    if (showStarter)
        printSubHeading("SEARCH ITEM");

    printInfo("\n- Type `exit` to go back\n");
    printInfo("- Search by:\n1. ID\n2. Name \n");

    fflush(stdin);
    fgets(input, 1000, stdin);

    if (strcmp(input, "exit\n") == 0)
        return;
    else if (strcmp(input, "1\n") == 0)
    {
        searchById();
        searchWindow(0);
    }
    else if (strcmp(input, "2\n") == 0)
    {
        searchByName();
        searchWindow(0);
    }
    else
        printError("Enter a valid option");
}
