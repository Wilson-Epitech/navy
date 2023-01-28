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

int first_terminal_in_game(void)
{
    int signal_send = 0;

    my_putstr("attack:");
    while (signal_send != 1) {
        pause();
    }
    return (0);
}

int second_terminal_in_game(void)
{
    int signal_send = 0;
    my_putstr("waiting for enemy's attack...");
    while (signal_send != 1) {
        pause();
    }
    return (0);
}

int terminals_in_game(int ac)
{
    if (ac == 2) {
        first_terminal_in_game();
    }

    if (ac == 3) {
        second_terminal_in_game();
    }

    return (0);
}
