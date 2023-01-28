/*
** NAVY PROJECT, 2022
** struct.h
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
typedef struct {
    int map_lines;
    int nb_of_lines;
    char *buffer;
    char **array;
    char *length;
    char *start;
    char *end;
    int x;
    int y;
    int i;
    char *letters;
    char *numbers;
    char **map_array;
    int error;
    int nb;
} structure_t;

#endif
