/*
** EPITECH PROJECT, 2023
** conflicto.c
** File description:
** conflicto
*/

#include "../include/my_radar.h"

void conflicto(sfRenderWindow *w, sfEvent ev, struct radar *r, int i)
{
    int j = 0; int si = 0; float a; float b;
    while (j < r->num_aviones && si == 0) {
        a = r->aviones[i]->posactual.x; b = r->aviones[j]->posactual.x;
        if (j != i && a == b) {
            si = conflicto_2(r, i, j);
        }
        j++;
    }
    if (si == 1) {
        borrar_avion(w, ev, r, i); borrar_avion(w, ev, r, j);
    }
}

int conflicto_2(struct radar *r, int i, int j)
{
    int si = 0;
    if (zona_radar(r->aviones[i]->posactual, r) != 1) {
            si = 1;
    }
    return si;
}

int zona_radar(sfVector2f a, struct radar *r)
{
    int i = 0; int rad = 0; int si_zona = 0;
    float x; float y;
    while (i < r->num_torres) {
        x = a.x - r->torres[i]->pos_tower.x; x = x * x;
        y = a.y - r->torres[i]->pos_tower.y; y = y * y;
        rad = calcule_percentage(r->torres[i]->percentage_radar);
        rad *= rad;
        if ((x + y) <= rad) {
            si_zona = 1;
        }
        i++;
    }
    return si_zona;
}
