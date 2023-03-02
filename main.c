#include <stdio.h>
#include "admin_window.c"
#include "welcome_screen.c"
#include "Admin_login.c"
#include "delay.c"
#include "user_interface.c"
int main()
{
    int num_wel, num_ad, num_adwin, num_user;
welcome:
    welcome();
    printf("Enter your choice here: ");
    scanf("%d", &num_wel);
    if (num_wel == 1)
    {
        goto admin;
    }
    else if (num_wel == 2) 
    {
        goto user;
    }
    else
    {
        printf("Please enter a valid choice\n");
        goto welcome;
    }

admin:
    num_ad = admin();
    delay();
    if (num_ad == 1)
    {
        goto admin_win;
    }
    else if (num_ad == 2)
    {
        printf("Closing");
        delay();
        goto welcome;
    }
    else
    {
        printf("Enter the correct password or 1 to exit\n");
        goto admin;
    }
admin_win:
    num_adwin = admin_window();
    if (num_adwin == 1)
    {
        printf("View available books");
    }
    else if (num_adwin == 2)
    {
        printf("Delete books");
    }
    else if (num_adwin == 3)
    {
        printf("Closing");
        delay();
        goto welcome;
    }
    else
    {
        printf("Please enter a valid option\n");
        goto admin_win;
    }

user:
    num_user = user_interface();
    if (num_user == 1)
    {
        printf("Donate books");
    }
    else if (num_user == 2)
    {
        printf("Borrow books");
    }
    else if (num_user == 3)
    {
        printf("Closing");
        delay();
        goto welcome;
    }
    else
    {
        printf("\nPlease enter a valid choice\n");
        goto user;
    }
}