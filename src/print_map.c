/*
** NAVY PROJECT, 2022
** main.c
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"
#include "navy.h"
#include "struct.h"

int print_defense_map(structure_t *st, structure_t stock[st->nb_of_lines])
{
    st->map_lines = 8;
    char *line = ". . . . . . . .\n";
    char *map = malloc(sizeof(char) * (my_strlen(line) * 8) + 1);
    my_putstr("my positions:\n");
    print_borders();
    fill_map(map);
    map_defense(st, stock, map);

}

int print_attack_map(structure_t *st, structure_t stock[st->nb_of_lines])
{
    st->map_lines = 8;
    char *line = ". . . . . . . .\n";
    char *map = malloc(sizeof(char) * (my_strlen(line) * 8) + 1);
    my_putstr("enemy's positions:\n");
    print_borders();
    fill_map(map);
    map_attack(st, stock, map);

}
