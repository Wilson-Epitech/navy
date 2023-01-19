/*
** NAVY PROJECT, 2022
** main.c
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "my.h"
#include "navy.h"
#include "struct.h"

void h_option(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player. ");
    my_putstr("pid of the first player.\n");
    my_putstr("\tnavy_positions: file representing ");
    my_putstr("the positions of the ships.\n");
}

int launch_game(char **av)
{
    structure_t *st = malloc(sizeof(structure_t));

    open_and_read_map(av, st);
    fill_array(st);
    structure_t stock[st->nb_of_lines];
    parsing(st, stock);
    print_map(st, stock);
    free(st->buffer);
    free(st->array);
    free(st);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        h_option();
        return (0);
    }
    if (ac == 2) {
        launch_game(av);
        return (0);
    }
    return (0);
}
