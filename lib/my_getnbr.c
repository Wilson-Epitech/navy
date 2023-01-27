/*
** NAVY PROJECT, 2022
** my_getnbr.c
** File description:
** pool
*/

#include <stdlib.h>
#include "my.h"

int return_nb(char const *str, int nb, int i)
{
    if (str[i + 1] < '0' || str[i + 1] > '9') {
        return (nb);
    }
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10 + (str[i] - '0');
            return_nb(str, nb, i);
        }
        i++;
    }

    if (nb < -2147483647 || nb > 2147483647) {
        my_putstr("error : maximal lenght outdated\n");
        return (84);
    } else {
        return (nb);
    }
}
