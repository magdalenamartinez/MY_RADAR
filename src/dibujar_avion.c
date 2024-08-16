/*
** EPITECH PROJECT, 2023
** dibujar_avion.c
** File description:
** dibujar avion
*/

#include "../include/my_radar.h"

void rotar_avion(sfRenderWindow *w, sfEvent ev, struct radar *r, int i)
{
    float tg = (float) r->aviones[i]->dif_y / r->aviones[i]->dif_x;
    r->aviones[i]->angle = 1 / tg;
}

void bucle_avion(sfRenderWindow *w, sfEvent ev, struct radar *r, int i)
{
    dif_fun(w, ev, r, i);
    rotar_avion(w, ev, r, i);
    id_sector(w, ev, r, i);
    conflicto(w, ev, r, i);
    dibujar_avion(w, ev, r, i);
}

void dif_fun(sfRenderWindow *w, sfEvent ev, struct radar *r, int i)
{
    if (r->aviones[i]->dif_x >= r->aviones[i]->dif_y) {
        r->aviones[i]->mov.x = r->aviones[i]->dif_x / r->aviones[i]->dif_y;
        r->aviones[i]->mov.x *= r->aviones[i]->speed / 2;
        r->aviones[i]->mov.y = 1 * r->aviones[i]->speed / 2;
        r->aviones[i]->pix.x += (int)r->aviones[i]->mov.x;
        r->aviones[i]->pix.y += (int)r->aviones[i]->mov.y;
    }
    if (r->aviones[i]->dif_x < r->aviones[i]->dif_y) {
        r->aviones[i]->mov.y = r->aviones[i]->dif_y / r->aviones[i]->dif_x;
        r->aviones[i]->mov.y *= r->aviones[i]->speed / 2;
        r->aviones[i]->mov.x = 1 * r->aviones[i]->speed / 2;
        r->aviones[i]->pix.x += (int)r->aviones[i]->mov.x;
        r->aviones[i]->pix.y += (int)r->aviones[i]->mov.y;
    }
}

void dibujar_avion(sfRenderWindow *w, sfEvent ev, struct radar *r, int i)
{
    sfSprite_setPosition(r->spavion, r->aviones[i]->posactual);
    sfSprite_setRotation(r->spavion, r->aviones[i]->angle);
    int ax = (int)r->aviones[i]->posactual.x;
    int ay = (int)r->aviones[i]->posactual.y;
    int bx = (int)r->aviones[i]->pos_final.x;
    int by = (int)r->aviones[i]->pos_final.y;
    if (ax == bx || ay == by) {
        borrar_avion(w, ev, r, i);
    } else {
        sfRenderWindow_drawSprite(w, r->spavion, NULL);
    }
}

void borrar_avion(sfRenderWindow *w, sfEvent ev, struct radar *r, int i)
{
    while (i < r->num_aviones - 1) {
        r->aviones[i] = r->aviones[i + 1];
        i++;
    }
    r->num_aviones--;
}
