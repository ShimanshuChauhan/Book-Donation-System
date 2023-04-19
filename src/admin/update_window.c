#include <stdio.h>
#include <stdlib.h>
#include "../data/data.h"
#include "../utils/print.c"

void updateWindow(int showStarter)
{
    char input[1000];
    if (showStarter)
        printSubHeading("UPDATE ITEM");

    printInfo("\n- Type `exit` to go back\n");
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
    printSubHeading("Select the field you want to update: \n");
    printInfo("1.Book Name\n2.Book Author\n3.Donated By\n4.Phone\n5.Address\n");
    char fieldToChange;
    scanf("%s", &fieldToChange);

    printInfo("Enter the new value: ");
    char newValue[1000];
    fflush(stdin);
    fgets(newValue, 1000, stdin);

    char *trimmedValue = strtok(newValue, "\n");

    updateBook(id,
               fieldToChange == '1' ? trimmedValue : book.name,
               fieldToChange == '2' ? trimmedValue : book.author,
               fieldToChange == '3' ? trimmedValue : book.donatedBy,
               fieldToChange == '4' ? trimmedValue : book.phone,
               fieldToChange == '5' ? trimmedValue : book.address);

    return;
}
