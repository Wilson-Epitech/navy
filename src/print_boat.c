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

int boat_in_x(structure_t *st, structure_t stock[st->nb_of_lines])
{
    while (st->numbers[st->y] != stock[st->x].end[1]) {
        st->map_array[st->y][st->i] = stock[st->x].length[0];
        st->y += 1;
    }
    st->map_array[st->y][st->i] = stock[st->x].length[0];
    return (0);
}

int boat_in_y(structure_t *st, structure_t stock[st->nb_of_lines])
{
    while (st->letters[st->i] != stock[st->x].end[0]) {
        st->map_array[st->y][st->i] = stock[st->x].length[0];
        st->i += 2;
    }
    st->map_array[st->y][st->i] = stock[st->x].length[0];
    return (0);

}

int print_boat(structure_t *st, structure_t stock[st->nb_of_lines])
{
    st->letters = "A B C D E F G H ";
    st->i = 0;

    while (st->letters[st->i] != stock[st->x].start[0])
        st->i++;

    st->numbers = "12345678";
    st->y = 0;

    while (st->numbers[st->y] != stock[st->x].start[1])
        st->y++;

    if (stock[st->x].start[0] != stock[st->x].end[0])
        boat_in_y(st, stock);

    if (stock[st->x].start[0] == stock[st->x].end[0])
        boat_in_x(st, stock);

}

int map_array(structure_t *st, structure_t stock[st->nb_of_lines], char *map)
{
    st->map_array = malloc(sizeof(char) * my_strlen(map));
    st->map_array = word_array_delimit(map);

    for (st->x = 0; st->x != st->nb_of_lines; st->x++) {
        print_boat(st, stock);
    }

    int compteur = 0;

    for (int x = 0; st->map_array[x + 1] != NULL; x++) {
        compteur++;
        my_put_nbr(compteur);
        my_putchar('|');
        my_putstr(st->map_array[x]);
        my_putchar('\n');
    }

}
