#include "minitalk.h"

int ft_atoi(const char *str)
{
    int i;
    int sign;
    int result;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
            str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
        i++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10;
        result = result + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

static void send_message(int pid, char *message)
{
    int i;
    int j;
    int bit;

    i = 0;
    while (message[i])
    {
        j = 0;
        while (j < 8)
        {
            bit = (message[i] >> j) & 1;
            if (bit == 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            j++;
            usleep(250);
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac < 3)
    {
        write(1, "Usage: ./client [PID] [message]\n", 32);
        return (1);
    }
    if (ft_atoi(av[1]) < 0)
    {
        write(1, "Invalid PID\n", 12);
        return (1);
    }
    send_message(ft_atoi(av[1]), av[2]);
}