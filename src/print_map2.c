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

void print_borders(void)
{
    char *pos_letters = " |A B C D E F G H";
    char *map_delim = "-+---------------";

    my_putstr(pos_letters);
    my_putchar('\n');
    my_putstr(map_delim);
    my_putchar('\n');
}

int fill_map(char *map)
{
    int i = 0;

    for (i = 0; i <= 127; i++) {
        if (i % 2 == 0) {
            map[i] = '.';
        }
        if (i % 2 != 0) {
            map[i] = ' ';
        }
        if (i == 15 || i == 31 || i == 47 ||
        i == 63 || i == 79 || i == 95 ||
        i == 111 || i == 127) {
            map[i] = '\n';
        }
    }
    map[i] = '\0';
}
