/*
** EPITECH PROJECT, 2023
** bucle.c
** File description:
** bucle
*/

#include "../include/my_radar.h"

void bucle(sfRenderWindow *w, sfEvent ev, struct radar *r)
{
    int i = 0; float t2; srand(time(NULL)); sfTime m; float t; sfTime m2;
    while (sfRenderWindow_isOpen(w)) {
        while (sfRenderWindow_pollEvent(w, &ev)) {
            cerrar_event(w, ev);
        }
        m = sfClock_getElapsedTime(r->reloj);
        t = m.microseconds / 1000000.0; r->s = (int)t;
        m2 = sfClock_getElapsedTime(r->reloj2);
        t2 = m2.microseconds / 1000000.0; r->s2 = (int)t2;
        sfRenderWindow_clear(w, sfWhite); choose_pantalla(w, ev, r);
        if (r->numpantalla == 1) {
            aviones_mostrar(w, ev, r, i); i = 0;
        }
        num_aviones_cero(r);
        event_click(w, ev, r); sfRenderWindow_display(w);
    }
    sfClock_restart(r->reloj); free_function(r);
}

void num_aviones_cero(struct radar *r)
{
    if (r->num_aviones == 0) {
        r->numpantalla = 0;
    }
}

void aviones_mostrar(sfRenderWindow *w, sfEvent ev, struct radar *r, int i)
{
    i = 0;
    while (i < r->num_aviones) {
        comprueba_bucle(w, ev, r, i); i++;
    }
}

void comprueba_bucle(sfRenderWindow *w, sfEvent ev, struct radar *r, int i)
{
    if (r->s >= r->aviones[i]->delay) {
        bucle_avion(w, ev, r, i);
    }
}

void cerrar_event(sfRenderWindow *w, sfEvent ev)
{
    if (ev.type == sfEvtClosed) {
        sfRenderWindow_close(w);
    }
}
