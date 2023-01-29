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

void free_all(structure_t *st)
{
    free(st->buffer);
    free(st->array);
    free(st);
}

int connect_terms(int ac, char **av)
{
    if (ac == 2) {
        first_terminal_infos(av);
    }

    if (ac == 3) {
        int check_pid = second_terminal_infos(av);
        if (check_pid != 0)
            return (check_pid);
    }
}

int launch_game(structure_t *st, structure_t stock[st->nb_of_lines])
{
    print_defense_map(st);
    fill_attack_map(st, stock);
    print_attack_map(st);
    free_all(st);
    return (0);
}

int check_and_launch(int ac, char **av)
{
    structure_t *st = malloc(sizeof(structure_t));
    int check = open_and_read_map(ac, av, st);
    if (check == 84)
        return (84);
    int check_lines = fill_array(st);
    if (check_lines == 84)
        return (84);
    structure_t stock[st->nb_of_lines];
    parsing(st, stock);
    if (st->error == 1)
        return (84);
    int check_map = fill_defense_map(st, stock);
    if (check_map == 84)
        return (84);
    int check_connection = connect_terms(ac, av);
    if (check_connection == 84)
        return (84);
    int check_game = launch_game(st, stock);
    if (check_game == 84)
        return (84);
}
