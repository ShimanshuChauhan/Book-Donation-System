#include "../utils/print.c"
#include "../data/data.h"

void adminWindow(int showStarter)
{
    char input;
    if (showStarter)
        printSubHeading("ADMIN WINDOW");

    printf("\nPlease select the task you want to perform: \n");
    printInfo("1.View available books\n2.Delete Books\n3.Close Application\n");
    printf("Enter your choice here: ");
    scanf("%s", &input);
    if (input == '1')
    {
        printSuccess("## List of Books:\n");
        getBooks();
        adminWindow(0);
    }
    else if (input == '2')
    {
        return;
    }
    else if (input == '3')
    {
        return;
    }
    else
    {
        printError("Enter a valid number!");
        adminWindow(0);
    }
}