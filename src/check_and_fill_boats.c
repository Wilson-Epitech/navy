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
    if (my_getnbr(stock[st->x].end) - my_getnbr(stock[st->x].start) !=
    my_getnbr(stock[st->x].length) - 1) {
        return (84);
    }

    while (st->numbers[st->y] != stock[st->x].end[1]) {
        st->map_array[st->y][st->i] = stock[st->x].length[0];
        st->y += 1;
    }
    st->map_array[st->y][st->i] = stock[st->x].length[0];
    return (0);
}

int boat_in_y(structure_t *st, structure_t stock[st->nb_of_lines])
{

    if ((stock[st->x].end[0] - stock[st->x].start[0]) !=
    my_getnbr(stock[st->x].length) - 1) {
        return (84);
    }

    while (st->letters[st->i] != stock[st->x].end[0]) {
        st->map_array[st->y][st->i] = stock[st->x].length[0];
        st->i += 2;
    }
    st->map_array[st->y][st->i] = stock[st->x].length[0];
    return (0);

}

int choose_your_boat(structure_t *st, structure_t stock[st->nb_of_lines])
{
    if (stock[st->x].start[0] != stock[st->x].end[0] &&
    stock[st->x].start[1] != stock[st->x].end[1])
        return (84);

    if (stock[st->x].start[0] == stock[st->x].end[0] &&
    stock[st->x].start[1] == stock[st->x].end[1])
        return (84);

    if (stock[st->x].start[0] != stock[st->x].end[0] &&
    stock[st->x].start[1] == stock[st->x].end[1]) {
        int check_boat_y = boat_in_y(st, stock);
        if (check_boat_y == 84)
            return (84);
    }
    if (stock[st->x].start[0] == stock[st->x].end[0] &&
    stock[st->x].start[1] != stock[st->x].end[1]) {
        int check_boat_x = boat_in_x(st, stock);
        if (check_boat_x == 84)
            return (84);
    }
}

int fill_boats(structure_t *st, structure_t stock[st->nb_of_lines])
{
    st->letters = "A B C D E F G H ";
    st->i = 0;
    st->numbers = "12345678";
    st->y = 0;
    while (st->letters[st->i] != stock[st->x].start[0])
        st->i++;

    while (st->numbers[st->y] != stock[st->x].start[1])
        st->y++;

    int check = choose_your_boat(st, stock);
    if (check == 84)
        return (84);

    return (0);
}

int check_boats(structure_t *st, structure_t stock[st->nb_of_lines], char *map)
{
    st->map_array = malloc(sizeof(char) * my_strlen(map));
    st->map_array = word_array_delimit(map);
    for (st->x = 0; st->x != st->nb_of_lines; st->x++) {
        int check_boats = fill_boats(st, stock);
        if (check_boats == 84) {
            return (84);
        }
    }

    return (0);
}
