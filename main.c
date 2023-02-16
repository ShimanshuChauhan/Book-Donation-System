#include <stdio.h>

#include "Admin_login.c"
#include "delay.c"
int main()
{
    // Get User type
    printf("                ############ BOOK MANAGEMENT SYSTEM ############\n");
    printf("                            xxxxxxx WELCOME xxxxxxx\n");
    printf("Select: \n 1.ADMIN LOGIN\n 2.USER LOGIN\n");
    int num;
    printf("Enter your choice: ");
    scanf("%d", &num);
    delay(1000000000);
    if (num == 1)
    {
        admin();
    }
}