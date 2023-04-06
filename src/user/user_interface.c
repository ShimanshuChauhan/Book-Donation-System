#include <stdio.h>
#include <stdlib.h>
#include "./donate_books.c"
#include "../utils/print.c"

void userInterface(int showStarter)

{
    if (showStarter)
        printSubHeading("WELCOME USER");

    printf("Please select from the following option\n");
    printInfo("1.Donate books\n2.Close Application");
    printf("\nEnter your choice here: ");
    char selection;
    scanf("%s", &selection);

    if (selection == '1')
    {
        int res = donateBooks();
        if (res == 1)
            printSuccess("\n\n** Congratulations you have successfully donated your book! ** \n\n");
        userInterface(0);
    }

    else if (selection == '2')
    {
        return;
    }
    else
        userInterface(0);
}