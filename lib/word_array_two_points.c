/*
** NAVY PROJECT, 2022
** my_str_to_word_array.c
** File description:
** pool day08
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int check_two_points(char const *str)
{
    int y = 0;
    int count_w = 0;

    while (str[y] != '\0') {
        if (str[y + 1] == ':') {
            count_w++;
        }
        y++;
    }
    return (count_w);
}

int str_array_points(char const *str, char **array)
{
    int i = 0;
    int x = 0;
    int number_of_characters = 0;

    for (i = 0; str[i] != '\0' ; i++) {
        if (str[i] == ':') {
            array[x] = malloc(sizeof(char) * (number_of_characters + 1));
            number_of_characters = 0;
            x++;
        } else {
            number_of_characters++;
        }
    }
    array[x] = malloc(sizeof(char) * (number_of_characters + 1));
    return (0);
}

int str_array_points2(char const *str, char **array)
{
    int i = 0;
    int x = 0;
    int y = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':') {
            array[x][y] = '\0';
            y = 0;
            x++;
        } else {
        array[x][y] = str[i];
        y++;
        }
    }
    array[x][y] = '\0';
    array[x + 1] = NULL;
    return (0);
}

char **word_array_two_points(char const *str)
{
    int number_of_words = check_two_points(str);

    char **array = malloc(sizeof(char *) * (number_of_words + 1));

    str_array_points(str, array);
    str_array_points2(str, array);

    return (array);
}
