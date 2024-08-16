/*
** EPITECH PROJECT, 2023
** pantalla.c
** File description:
** pantalla
*/

#include "../include/my_radar.h"
void choose_pantalla(sfRenderWindow *w, sfEvent ev, struct radar *r)
{
    if (r->numpantalla == 0) {
        pantalla_inicio(w, ev, r);
    }
    if (r->numpantalla == 1) {
        pantalla_juego(w, ev, r);
    }
}

void pantalla_inicio(sfRenderWindow *w, sfEvent ev, struct radar *r)
{
    sfVector2f s = {1, 1.1}; sfSprite_setScale(r->pantallainicial, s);
    sfRenderWindow_drawSprite(w, r->pantallainicial, NULL);
}

void pantalla_juego(sfRenderWindow *w, sfEvent ev, struct radar *r)
{
    sfVector2f s = {1, 1.05}; sfSprite_setScale(r->pantallajuego, s);
    sfRenderWindow_drawSprite(w, r->pantallajuego, NULL);
    bucle_dibujar_torre(w, ev, r); dibujar_timer(w, ev, r);
}
