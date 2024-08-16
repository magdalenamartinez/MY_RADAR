/*
** EPITECH PROJECT, 2022
** int_to_string.c
** File description:
** convert
*/

#include "../include/my_radar.h"
char* int_to_str(int n)
{
    int len = 0;
    len = my_int_length(n);
    char *s; int i = 0; int div = 1;
    s = malloc(sizeof(char)*(len + 1));
    while (i < len) {
        s[i] = (n / div % 10) + 48;
        div = div * 10; i++;
    }
    s[i] = '\0';
    s = my_revstr(s);
    return (s);
}

int my_int_length(int n)
{
    int len = 0;
    if (n == 0) {
        len = 1;
    }
    while (n > 0) {
        n = n / 10;
        len++;
    }
    return len;
}
