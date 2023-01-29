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

int print_defense_map(structure_t *st)
{

    my_putstr("my positions:\n");
    print_borders();

    int compteur = 0;

    for (int x = 0; st->map_array[x + 1] != NULL; x++) {
        compteur++;
        my_put_nbr(compteur);
        my_putchar('|');
        my_putstr(st->map_array[x]);
        my_putchar('\n');
    }
    my_putchar('\n');

    return (0);
}

int print_attack_map(structure_t *st)
{
    my_putstr("enemy's positions:\n");
    print_borders();

    int compteur = 0;

    for (int x = 0; st->map_array[x + 1] != NULL; x++) {
        compteur++;
        my_put_nbr(compteur);
        my_putchar('|');
        my_putstr(st->map_array[x]);
        my_putchar('\n');
    }
    my_putchar('\n');

    return (0);
}
