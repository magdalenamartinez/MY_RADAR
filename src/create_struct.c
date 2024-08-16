/*
** EPITECH PROJECT, 2023
** create_struct.c
** File description:
** createstruct
*/

#include "../include/my_radar.h"
void function_createsprites(sfRenderWindow *w, sfEvent ev, char *buffer)
{
    struct radar *r = malloc(sizeof(struct radar));
    r->pantallainicial = malloc(sizeof(sfSprite*));
    r->botoninicio = malloc(sizeof(sfSprite*));
    r->pantallajuego = malloc(sizeof(sfSprite*));
    r->sptower = malloc(sizeof(sfSprite*));
    r->spavion = malloc(sizeof(sfSprite*));
    r->reloj = malloc(sizeof(sfClock*));
    r->reloj2 = malloc(sizeof(sfClock*));
    r->radio = malloc(sizeof(sfCircleShape*));
    r->font = malloc(sizeof(sfFont*));
    r->timer_tx = malloc(sizeof(sfText*));
    r->timer_tx = sfText_create();
    r->font = sfFont_createFromFile("./arc/font.ttf");
    r->numpantalla = 0; r->s = 0; r->s2 = 0;
    r->reloj = sfClock_create();
    r->reloj2 = sfClock_create();
    r->num_aviones_final = r->num_aviones; int i = 0;
    read_buffer(buffer, r);
    complete_struct(r); send_to_complete(r);
    bucle(w, ev, r);
}

void complete_struct(struct radar *r)
{
    r->pantallainicial = crea(sfTexture_createFromFile("arc/in3.jpg", NULL));
    r->botoninicio = crea(sfTexture_createFromFile("arc/bini.jpg", NULL));
    r->pantallajuego = crea(sfTexture_createFromFile("arc/mapaazul.jpg", NULL));
    r->spavion = crea(sfTexture_createFromFile("arc/plane.png", NULL));
    r->sptower = crea(sfTexture_createFromFile("arc/tower.png", NULL));
}

sfSprite* crea(sfTexture *t)
{
    sfSprite *spr = sfSprite_create();
    sfSprite_setTexture(spr, t, sfTrue);
    return (spr);
}

void read_buffer(char *buffer, struct radar *r)
{
    int i = 0;
    r->buffer = malloc(sizeof(char) * my_strlen(buffer));
    while (buffer[i] != '\0') {
        r->buffer[i] = buffer[i]; i++;
    }
    r->buffer[i] = '\0';
}

void free_function(struct radar *r)
{
    free(r->reloj2);
    free(r->reloj);
    free(r->pantallainicial);
    free(r->pantallajuego);
    free(r->botoninicio);
    free(r->sptower);
    free(r->spavion);
    free(r->timer_tx);
    free(r->font);
}
