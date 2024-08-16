/*
** EPITECH PROJECT, 2023
** sector.c
** File description:
** sector
*/

#include "../include/my_radar.h"

void id_sector(sfRenderWindow *w, sfEvent ev, struct radar *r, int i)
{
    int x = 0; int y = 0;
    x = r->aviones[i]->pos_final.x - r->aviones[i]->pos_inicio.x;
    y = r->aviones[i]->pos_final.y - r->aviones[i]->pos_inicio.y;
    if (x >= 0 && y >= 0) {
        sector_1(w, ev, r, i);
    }
    if (x < 0 && y >= 0) {
        sector_2(w, ev, r, i);
    }
    if (x < 0 && y < 0) {
        sector_3(w, ev, r, i);
    }
    if (x >= 0 && y < 0) {
        sector_4(w, ev, r, i);
    }
}

void sector_1(sfRenderWindow *w, sfEvent ev, struct radar *r, int i)
{
    if (r->s2 >= 0.5) {
        r->aviones[i]->posactual.x += r->aviones[i]->mov.x;
        r->aviones[i]->posactual.y += r->aviones[i]->mov.y;
        sfClock_restart(r->reloj2);
    }
    if (r->aviones[i]->dif_y > r->aviones[i]->dif_x) {
        r->aviones[i]->angle = 90 - r->aviones[i]->angle;
    }
}

void sector_2(sfRenderWindow *w, sfEvent ev, struct radar *r, int i)
{
    if (r->s2 >= 0.5) {
        r->aviones[i]->posactual.x -= r->aviones[i]->mov.x;
        r->aviones[i]->posactual.y += r->aviones[i]->mov.y;
        sfClock_restart(r->reloj2);
    }
    if (r->aviones[i]->dif_y > r->aviones[i]->dif_x) {
        r->aviones[i]->angle = 90 - r->aviones[i]->angle;
        r->aviones[i]->angle = 180 - r->aviones[i]->angle;
    } else {
        r->aviones[i]->angle = 180 - r->aviones[i]->angle;
    }
}

void sector_3(sfRenderWindow *w, sfEvent ev, struct radar *r, int i)
{
    if (r->s2 >= 0.5) {
        r->aviones[i]->posactual.x -= r->aviones[i]->mov.x;
        r->aviones[i]->posactual.y -= r->aviones[i]->mov.y;
        sfClock_restart(r->reloj2);
    }
    if (r->aviones[i]->dif_y > r->aviones[i]->dif_x) {
        r->aviones[i]->angle = 90 - r->aviones[i]->angle;
        r->aviones[i]->angle = 180 + r->aviones[i]->angle;
    } else {
        r->aviones[i]->angle = 180 +  r->aviones[i]->angle;
    }
}

void sector_4(sfRenderWindow *w, sfEvent ev, struct radar *r, int i)
{
    if (r->s2 >= 0.5) {
        r->aviones[i]->posactual.x += r->aviones[i]->mov.x;
        r->aviones[i]->posactual.y -= r->aviones[i]->mov.y;
        sfClock_restart(r->reloj2);
    }
    if (r->aviones[i]->dif_y > r->aviones[i]->dif_x) {
        r->aviones[i]->angle = 90 - r->aviones[i]->angle;
        r->aviones[i]->angle = 360 - r->aviones[i]->angle;
    } else{
        r->aviones[i]->angle = 360 -  r->aviones[i]->angle;
    }
}
