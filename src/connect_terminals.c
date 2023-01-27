/*
** NAVY PROJECT, 2023
** my_navy
** File description:
** connect_terminals
*/

#include "my.h"
#include "navy.h"
#include "struct.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int is_connected = 0;

void manage_sigusr2(int signal)
{
    if (signal == SIGUSR2) {
        my_putstr("enemy connected\n");
        is_connected = 1;
    }

}

int first_terminal_infos(char **av)
{
    int pid_terminal1 = getpid();
    my_putstr("my_pid: ");
    my_put_nbr(pid_terminal1);
    my_putstr("\nwaiting for enemy connection...\n\n");

    struct sigaction sigac;
    sigac.sa_handler = manage_sigusr2;
    sigaction(SIGUSR2, &sigac, NULL);

    while (is_connected != 1) {
        pause();
    }
    return 0;
}

int second_terminal_infos(char **av)
{
    int pid_terminal2 = getpid();

    int is_pid_terminal1 = my_getnbr(av[1]);
    int is_send = kill(is_pid_terminal1, SIGUSR2);
    if (is_send == 0) {
        my_putstr("my_pid: ");
        my_put_nbr(pid_terminal2);
        my_putchar('\n');
        my_putstr("successfully connected\n");
    } else {
        return (84);
    }
    return (0);
}
