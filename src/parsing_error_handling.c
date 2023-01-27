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

int check_length(char *str, structure_t *st)
{
    if (my_strlen(str) != 1) {
        st->error = 1;
        return (84);
    }

    if (str[0] < '2' || str[0] > '8') {
        st->error = 1;
        return (84);
    }

    return (0);
}

int check_str(char *str, structure_t *st)
{
    if (my_strlen(str) != 2) {
        st->error = 1;
        return (84);
    }

    if (str[0] < 'A' || str[0] > 'H') {
        st->error = 1;
        return (84);
    }

    if (str[1] < '1' || str[1] > '8') {
        st->error = 1;
        return (84);
    }

    return (0);
}
