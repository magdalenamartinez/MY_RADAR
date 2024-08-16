/*
** EPITECH PROJECT, 2023
** complete_toweravion.c
** File description:
** complete tower avion
*/

#include "../include/my_radar.h"

void send_to_complete(struct radar *r)
{
    int j = 0; int n = 0;
    num_planes(r); num_towers(r); int i = 0;
    r->aviones = (struct avion**)malloc(sizeof(struct avion*)*r->num_aviones);
    r->torres = (struct torre**)malloc(sizeof(struct torre*)*r->num_torres);
    while (r->buffer[i] != '\0') {
        if (r->buffer[i] == 'A') {
            r->i = i;
            complete_avion(r, j); j++;
        }
        if (r->buffer[i] == 'T') {
            r->i = i; complete_tower(r, n); n++;
        }
        i++;
    }
}

void complete_avion(struct radar *r, int j)
{
    r->aviones[j] = malloc(sizeof(struct avion));
    r->i = f_nospaces(r->buffer, r->i);
    r->i = f_spaces(r->buffer, r->i);
    r->aviones[j]->pos_inicio.x = read_pos(r, r->i);
    r->i = f_spaces(r->buffer, r->i);
    r->aviones[j]->pos_inicio.y = read_pos(r, r->i);
    r->i = f_spaces(r->buffer, r->i);
    r->aviones[j]->pos_final.x = read_pos(r, r->i);
    r->i = f_spaces(r->buffer, r->i);
    r->aviones[j]->pos_final.y = read_pos(r, r->i);
    r->i = f_spaces(r->buffer, r->i);
    r->aviones[j]->speed = read_pos(r, r->i);
    r->i = f_spaces(r->buffer, r->i);
    r->aviones[j]->delay = read_pos(r, r->i);
    complete_avion2(r, j);
}

void complete_avion2(struct radar *r, int j)
{
    float posfinalx = r->aviones[j]->pos_final.x;
    float posinicioy = r->aviones[j]->pos_inicio.y;
    if (posfinalx > r->aviones[j]->pos_inicio.x) {
        r->aviones[j]->dif_x = posfinalx - r->aviones[j]->pos_inicio.x;
    } else {
        r->aviones[j]->dif_x = r->aviones[j]->pos_inicio.x - posfinalx;
    }
    if (r->aviones[j]->pos_final.y > r->aviones[j]->pos_inicio.y) {
        r->aviones[j]->dif_y = r->aviones[j]->pos_final.y - posinicioy;
    } else {
        r->aviones[j]->dif_y = posinicioy- r->aviones[j]->pos_final.y;
    }
    r->aviones[j]->posactual.x = r->aviones[j]->pos_inicio.x;
    r->aviones[j]->posactual.y = r->aviones[j]->pos_inicio.y;
    r->aviones[j]->pix.x = 0;
    r->aviones[j]->pix.y = 0;
}

void complete_tower(struct radar *r, int n)
{
    r->torres[n] = malloc(sizeof(struct torre));
    r->i = f_nospaces(r->buffer, r->i);
    r->i = f_spaces(r->buffer, r->i);
    r->torres[n]->pos_tower.x = read_pos(r, r->i);
    r->i = f_spaces(r->buffer, r->i);
    r->torres[n]->pos_tower.y = read_pos(r, r->i);
    r->i = f_spaces(r->buffer, r->i);
    r->torres[n]->percentage_radar = read_pos(r, r->i);
}
