/*
** NAVY PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char **word_array_non_alpha(char const *str);
char **word_array_delimit(char const *str);
char **word_array_two_points(char const *str);
#endif
