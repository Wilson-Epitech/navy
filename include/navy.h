/*
** NAVY PROJECT, 2022
** projet.h
** File description:
** projet.h
*/

#ifndef NAVY_H_
    #define NAVY_H_
    #include "struct.h"
int open_and_read_map(char **av, structure_t *st);
int fill_array(structure_t *st);
int parsing(structure_t *st, structure_t stock[st->nb_of_lines]);
int map_array(structure_t *st, structure_t stock[st->nb_of_lines], char *map);
int print_map(structure_t *st,  structure_t stock[st->nb_of_lines]);
#endif
