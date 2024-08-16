/*
** EPITECH PROJECT, 2023
** dibujar.c
** File description:
** dibujar
*/

#include "../include/my_radar.h"
void bucle_dibujar_torre(sfRenderWindow *w, sfEvent ev, struct radar *r)
{
    int i = 0;
    while (i < r->num_torres) {
        dibujar_torre(w, ev, r, i);
        i++;
    }
}

void dibujar_torre(sfRenderWindow *w, sfEvent ev, struct radar *r, int i)
{
    float p = 0;
    sfVector2f pos = {r->torres[i]->pos_tower.x, r->torres[i]->pos_tower.y};
    sfCircleShape *s;
    s = malloc(sizeof(sfCircleShape*));
    s = sfCircleShape_create();
    p = calcule_percentage(r->torres[i]->percentage_radar);
    sfCircleShape_setRadius(s, p); int t = p - 64;
    sfVector2f poscircle = {pos.x + 128 - p - 64, pos.y + 128 - p};
    sfCircleShape_setPosition(s, poscircle);
    sfCircleShape_setFillColor(s, sfTransparent);
    sfCircleShape_setOutlineColor(s, sfBlack);
    sfCircleShape_setOutlineThickness(s, 5);
    sfSprite_setPosition(r->sptower, pos);
    sfRenderWindow_drawSprite(w, r->sptower, NULL);
    sfRenderWindow_drawCircleShape(w, s, NULL);
}

float calcule_percentage(int n)
{
    float p = 0;
    p = (1920 * n) / 100;
    return p;
}

void num_planes(struct radar *r)
{
    int i = 0; int num = 0;
    while (r->buffer[i] != '\0') {
        if (r->buffer[i] == 'A') {
            r->num_aviones++;
        }
        i++;
    }
}

void num_towers(struct radar *r)
{
    int i = 0; int num = 0;
    while (r->buffer[i] != '\0') {
        if (r->buffer[i] == 'T') {
            r->num_torres++;
        }
        i++;
    }
}
