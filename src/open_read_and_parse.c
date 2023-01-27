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

int parsing(structure_t *st, structure_t stock[st->nb_of_lines])
{
    int y = 0;

    for (int x = 0; st->array[x] != NULL; x++) {
        if (x == 0 || x == 3 || x == 6 || x == 9) {
            check_length(st->array[x], st);
            stock[y].length = st->array[x];
        }

        if (x == 1 || x == 4 || x == 7 || x == 10) {
            check_str(st->array[x], st);
            stock[y].start = st->array[x];
        }

        if (x == 2 || x == 5 || x == 8 || x == 11) {
            check_str(st->array[x], st);
            stock[y].end = st->array[x];
            y += 1;
        }
    }
    return (0);
}

int fill_array(structure_t *st)
{
    st->nb_of_lines = 0;
    st->array = malloc(sizeof(my_strlen(st->buffer + 1)));
    st->array = word_array_non_alpha(st->buffer);

    int x = 0;
    while (st->buffer[x] != '\0') {
        if (st->buffer[x] == ':') {
            st->nb_of_lines++;
        }
        x++;
    }
    if (st->nb_of_lines != 8) {
        return (84);
    }
    st->nb_of_lines = st->nb_of_lines / 2;
    return (0);
}

int check_map(structure_t *st)
{
    int count = 0;
    for (int i = 0; st->buffer[i] != '\0'; i++) {
        if (st->buffer[i] != ':' && st->buffer[i] != '\n'
        && st->buffer[i] < '1' || st->buffer[i] != ':' && st->buffer[i] != '\n'
        && st->buffer[i] > '8' && st->buffer[i] < 'A' || st->buffer[i] != ':'
        && st->buffer[i] != '\n' && st->buffer[i] > 'H')
            return (84);
    }
    return (0);
}

int open_and_read_map(int ac, char **av, structure_t *st)
{
    char const *filepath;
    if (ac == 2)
        filepath = av[1];
    if (ac == 3)
        filepath = av[2];
    int fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return (84);
    int size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    st->buffer = malloc(sizeof(char) * (size + 1));
    st->buffer[size] = '\0';
    read(fd, st->buffer, size);
    if (my_strlen(st->buffer) <= 3)
        return 84;
    int check = check_map(st);
    if (check == 84)
        return (84);
    close(fd);
    return (0);
}
