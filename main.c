#include <stdio.h>
#include "admin_window.c"
#include "welcome_screen.c"
#include "Admin_login.c"
#include "delay.c"
int main()
{
int num_wel,num_ad,num_adwin;
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
    else
    {
        printf("Please enter the correct password \n \n");
        goto admin;
    }
admin_win:
    num_adwin=admin_window();
    if (num_adwin== 1)
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
        printf("Please select correctly");
        goto admin_win;
    }

user:
    printf("User");
}