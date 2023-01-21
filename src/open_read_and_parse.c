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
            stock[y].length = st->array[x];
        }

        if (x == 1 || x == 4 || x == 7 || x == 10) {
            stock[y].start = st->array[x];
        }

        if (x == 2 || x == 5 || x == 8 || x == 11) {
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
    st->nb_of_lines = st->nb_of_lines / 2;
    return (0);
}

int open_and_read_map(char **av, structure_t *st)
{
    char const *filepath = av[1];
    int fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return (84);
    int size = 32;
    st->buffer = malloc(sizeof(char) * (size + 1));
    st->buffer[size] = '\0';
    read(fd, st->buffer, size);
    if (my_strlen(st->buffer) <= 3)
        return 84;
    close(fd);
    return (0);
}
