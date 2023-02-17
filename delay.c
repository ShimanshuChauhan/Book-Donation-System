#include <stdio.h>

// Pass the Duration you want to delay for
void delay()
{
    for (double i = 0; i < 1000000000; i++)
    {
        if (i == 44444)
        {
            printf(".");
        }
        else if (i == 77777777)
        {
            printf(".");
        }
        else if (i == 999999999)
        {
            printf(".");
        }
    }
    printf("\n");

}