/*
** NAVY PROJECT, 2022
** projet.h
** File description:
** projet.h
*/

#ifndef NAVY_H_
    #define NAVY_H_
    #include "struct.h"
int open_and_read_map(int ac, char **av, structure_t *st);
void print_borders(void);
int fill_map(char *map);
int fill_array(structure_t *st);
int parsing(structure_t *st, structure_t stock[st->nb_of_lines]);
int map_defense(structure_t *st, structure_t stock[st->nb_of_lines], char *map);
int map_attack(structure_t *st, structure_t stock[st->nb_of_lines], char *map);
int print_defense_map(structure_t *st,  structure_t stock[st->nb_of_lines]);
int print_attack_map(structure_t *st,  structure_t stock[st->nb_of_lines]);
int first_terminal_infos(char **av);
int second_terminal_infos(char **av);
int check_length(char *str, structure_t *st);
int check_str(char *str, structure_t *st);
#endif
