#include "./admin/admin_login.c"
#include "./user/user_interface.c"
#include "./utils/print.c"

void welcome(int showStarter)
{
    if (showStarter)
    {
        printHeading("BOOK MANAGEMENT SYSTEM");
        printSubHeading("WELCOME");
    }
    else
        printf("\n\n");

    printf("Select from the following to continue: \n");
    printInfo("1.ADMIN LOGIN\n2.USER LOGIN\n");
    printf("Enter your choice here:\n");
    char selection;
    scanf("%s", &selection);

    if (selection == '1')
    {
        adminLogin();
        welcome(0);
    }
    else if (selection == '2')
    {
        userInterface(1);
        welcome(0);
    }
    else
    {
        printError("Enter a valid option\n");
        welcome(0);
    }
}