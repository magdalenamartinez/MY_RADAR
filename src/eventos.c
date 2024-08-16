/*
** EPITECH PROJECT, 2023
** events.c
** File description:
** events
*/

#include "../include/my_radar.h"

void event_click(sfRenderWindow *window, sfEvent event, struct radar *r)
{
    int var = 0;
    r->raton = sfMouse_getPositionRenderWindow(window);
    if (r->raton.x >= 662 && r->raton.x <= 1318) {
        var = 1;
    }
    if (var == 1 && r->raton.y >= 660 && r->raton.y <= 810) {
        if (event.type == sfEvtMouseButtonPressed && r->numpantalla == 0) {
            r->numpantalla = 1;
        }
    }
}
