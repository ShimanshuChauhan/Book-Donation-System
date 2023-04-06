#include "../utils/print.c"
#include "../data/data.h"
#include "./search_window.c"
#include "./delete_window.c"

void adminWindow(int showStarter)
{
    char input;
    if (showStarter)
        printSubHeading("ADMIN WINDOW");

    printf("\nPlease select the task you want to perform: \n");
    printInfo("1.View available books\n2.Delete Books\n3.Search Book\n4.Go Back\n");
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
        deleteWindow(1);
        adminWindow(0);
    }
    else if (input == '3')
    {
        searchWindow(1);
        adminWindow(0);
    }
    else if (input == '4')
    {
        return;
    }
    else
    {
        printError("Enter a valid number!");
        adminWindow(0);
    }
}