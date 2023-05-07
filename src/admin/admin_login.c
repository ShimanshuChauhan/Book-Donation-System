#include "../utils/print.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./admin_window.c"

void adminLogin()
{

    // TODO: Set you password here
    char password[50];
    printSubHeading("ADMIN LOGIN");
    printInfo("- Type `exit` to exit\n");
    printInfo("- Enter Admin Password: ");
    scanf("%s", password);

    if (!strcmp(password, "admin"))
        adminWindow(1);
    else if (!strcmp(password, "exit"))
        return;
    else
    {
        printError("Invalid Password Try again!");
        adminLogin();
    }
}