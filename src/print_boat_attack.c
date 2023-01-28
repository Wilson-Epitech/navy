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

int map_attack(structure_t *st, structure_t stock[st->nb_of_lines], char *map)
{
    st->map_array = malloc(sizeof(char) * my_strlen(map));
    st->map_array = word_array_delimit(map);

    int compteur = 0;

    for (int x = 0; st->map_array[x + 1] != NULL; x++) {
        compteur++;
        my_put_nbr(compteur);
        my_putchar('|');
        my_putstr(st->map_array[x]);
        my_putchar('\n');
    }
    my_putchar('\n');

}
