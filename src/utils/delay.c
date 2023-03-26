#include <stdio.h>
#include <unistd.h>
#include <time.h>

void delay_ms(int ms)
{
    clock_t end_time = clock() + ((ms * CLOCKS_PER_SEC) / 1000);
    while (clock() < end_time)
    {
    }
}

// Pass the Duration you want to delay for
void addDelay()
{
    printf("\n");
    delay_ms(750);
    printf(".");
    delay_ms(750);
    printf(".");
    delay_ms(750);
    printf(".");
    printf("\n");
}