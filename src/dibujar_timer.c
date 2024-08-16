/*
** EPITECH PROJECT, 2023
** dibujar_timer.c
** File description:
** dibujartimer
*/

#include "../include/my_radar.h"

void dibujar_timer(sfRenderWindow *w, sfEvent ev, struct radar *r)
{
    sfVector2f pos = {1800, 970};
    timer_function(r);
    sfText_setString(r->timer_tx, r->timer);
    sfText_setFont(r->timer_tx, r->font);
    sfText_setCharacterSize(r->timer_tx, 40);
    sfText_setColor(r->timer_tx, sfBlack);
    sfText_setPosition(r->timer_tx, pos);
    sfRenderWindow_drawText(w, r->timer_tx, NULL);
}

void timer_function(struct radar *r)
{
    int min = 0; int seg = 0; int n = 1; min = r->s / 60;
    int m = min; seg = r->s % 60; int i = 0; int j = 0;
    while (m > 0) {
        m /= 10;
        n++;
    }
    char * minutos; minutos = malloc(sizeof(char) * n);
    if (min > 0) {
        minutos = int_to_str(min);
    } else {
        minutos = "00";
    }
    char * segundos; segundos = malloc(sizeof(char) * 2);
    if (seg > 0) {
        segundos = int_to_str(seg);
    } else {
        segundos = "00";
    }
    timer_function_second(r, minutos, segundos);
}

void timer_function_second(struct radar *r, char* minutos, char* segundos)
{
    int i = 0; int j = 0; int n = 0; int t = sizeof(char) * 3;
    r->timer = malloc((sizeof(char) * sizeof(my_strlen(minutos))) + t);
    while (minutos[i] != '\0') {
        r->timer[i] = minutos[i]; i++;
    }
    r->timer[i] = ':'; i++; n = 0;
    while (segundos[n] != '\0') {
        n++;
    }
    if (n == 1) {
        r->timer[i] = '0'; i++;
    }
    while (segundos[j] != '\0') {
        r->timer[i] = segundos[j]; i++; j++;
    }
    r->timer[i] = '\0';
}
