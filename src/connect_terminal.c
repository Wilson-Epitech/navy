/*
** NAVY PROJECT, 2022
** main.c
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "my.h"
#include "navy.h"

int who_sig_me(void)
{
    return (0);
}

int process_info(void)
{
    int pid = getpid();
    int ppid = getppid();
    int pgid = getgid();
    printf("PID = %d\n", pid);
    printf("PPID = %d\n", ppid);
    printf("PGID = %d\n", pgid);
    return (0);
}

int kill_it(char **av)
{
    int kill_it = kill(my_getnbr(av[1]), SIGQUIT);
    printf("kill_it = %d\n", kill_it);
    return (0);
}
