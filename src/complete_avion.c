/*
** EPITECH PROJECT, 2023
** complete_avion.c
** File description:
** complete avion
*/

#include "../include/my_radar.h"
int f_nospaces(char *buffer, int i)
{
    while (buffer[i] != ' ') {
        i++;
    }
    return i;
}

int f_spaces(char *buffer, int i)
{
    while (buffer[i] == ' ') {
        i++;
    }
    return i;
}

int read_pos(struct radar *r, int i)
{
    char *num; int n = 0; n = r->i; int j = 0;
    while (r->buffer[r->i] != ' ') {
        r->i++;
    }
    num = malloc(sizeof(char)* (r->i - n)); char a = r->buffer[n];
    while (a != ' ' && a != '\n' && a != '\0') {
        num[j] = r->buffer[n];
        n++; j ++; a = r->buffer[n];
    }
    return my_getnbr(num);
}
