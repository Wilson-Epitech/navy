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

int launch_game(int ac, char **av)
{
    structure_t *st = malloc(sizeof(structure_t));
    st->error = 0;
    int check = open_and_read_map(ac, av, st);
    if (check == 84) {
        return (84);
    }
    int check2 = fill_array(st);
    if (check2 == 84) {
        return (84);
    }
    structure_t stock[st->nb_of_lines];
    parsing(st, stock);
    if (st->error == 1) {
        return (84);
    }
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
        first_terminal_infos(av);
        int check_game_p1 = launch_game(ac, av);
        if (check_game_p1 == 84)
            return (84);
    }
    if (ac == 3) {
        int check = second_terminal_infos(av);
        if (check != 0)
            return (check);
        int check_game_p2 = launch_game(ac, av);
        if (check_game_p2 == 84)
            return (84);
    }
    return (0);
}
