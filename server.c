#include "minitalk.h"
#include <stdio.h>

static void handler(int signum)
{
    static int i = 0;
    static char c = 0;

    if (signum == SIGUSR1)
        c |= (1 << i);
    i++;
    if (i == 8)
    {
        write(1, &c, 1);
        i = 0;
        c = 0;
    }
}

int main()
{
    int pid;
    int i;
    char c;

    pid = getpid();
    write(1, "PID: ", 5);
    printf("%d\n", pid);
    write(1, "\n", 1);
    while (1)
    {
        i = 0;
        while (i < 8)
        {
            signal(SIGUSR1, handler);
            signal(SIGUSR2, handler);
            pause();
            i++;
        }
        write(1, &c, 1);
    }
}