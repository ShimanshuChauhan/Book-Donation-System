#include <stdio.h>

// Pass the Duration you want to delay for
void delay(int millis)
{
    for (double i = 0; i < millis; i++)
    {
        if (i == millis / 3)
        {
            printf(".");
        }
        else if (i == millis / 2)
        {
            printf(".");
        }

    }
        printf(".");

}