/*
** EPITECH PROJECT, 2023
** myradar.h
** File description:
** myradar
*/

#ifndef MY_RADAR_H_
    #define MY_RADAR_H_
    #include "my.h"
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Network.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <unistd.h>
    #define MAXBUFFER 2000000
    struct avion {
        sfVector2f pos_inicio;
        sfVector2f pos_final;
        sfVector2i pix;
        int speed;
        int delay;
        sfVector2f posactual;
        sfVector2f mov;
        int dif_x;
        int dif_y;
        float angle;
    };
    struct torre {
        sfVector2f pos_tower;
        int percentage_radar;
    };
    struct radar {
        char *timer;
        sfSprite *pantallainicial;
        sfSprite *botoninicio;
        sfSprite *pantallajuego;
        sfSprite *sptower;
        sfSprite *spavion;
        sfClock *reloj;
        sfClock *reloj2;
        sfText *timer_tx;
        sfFont *font;
        sfVector2i raton;
        struct avion **aviones;
        int num_aviones;
        int num_aviones_final;
        struct torre **torres;
        int num_torres;
        int numpantalla;
        char *buffer;
        int i;
        int j;
        int s;
        int s2;
        sfTime m;
        sfVector2f pix;
        sfCircleShape *radio;
    };
    void borrar_avion(sfRenderWindow *w, sfEvent ev, struct radar *r, int i);
    void dibujar_avion(sfRenderWindow *w, sfEvent ev, struct radar *r, int i);
    void bucle_avion(sfRenderWindow *w, sfEvent ev, struct radar *r, int i);
    void dif_fun(sfRenderWindow *w, sfEvent ev, struct radar *r, int i);
    void rotar_avion(sfRenderWindow *w, sfEvent ev, struct radar *r, int i);
    void bucle_dibujar_torre(sfRenderWindow *w, sfEvent ev, struct radar *r);
    void dibujar_torre(sfRenderWindow *w, sfEvent ev, struct radar *r, int i);
    float calcule_percentage(int n);
    void num_planes(struct radar *r);
    void num_towers(struct radar *r);
    void dibujar_timer(sfRenderWindow *w, sfEvent ev, struct radar *r);
    void timer_function(struct radar *r);
    void timer_function_second(struct radar *r, char* minutos, char* segundos);
    void send_to_complete(struct radar *r);
    void complete_avion(struct radar *r, int j);
    void complete_avion2(struct radar *r, int j);
    void complete_tower(struct radar *r, int n);
    void cerrar_event(sfRenderWindow *w, sfEvent ev);
    void comprueba_bucle(sfRenderWindow *w, sfEvent ev, struct radar *r, int i);
    void aviones_mostrar(sfRenderWindow *w, sfEvent ev, struct radar *r, int i);
    void num_aviones_cero(struct radar *r);
    void bucle(sfRenderWindow *w, sfEvent ev, struct radar *r);
    void free_function(struct radar *r);
    void read_buffer(char *buffer, struct radar *r);
    sfSprite* crea(sfTexture *t);
    void complete_struct(struct radar *r);
    void function_createsprites(sfRenderWindow *w, sfEvent ev, char *buffer);
    void id_sector(sfRenderWindow *w, sfEvent ev, struct radar *r, int i);
    void sector_1(sfRenderWindow *w, sfEvent ev, struct radar *r, int i);
    void sector_2(sfRenderWindow *w, sfEvent ev, struct radar *r, int i);
    void sector_3(sfRenderWindow *w, sfEvent ev, struct radar *r, int i);
    void sector_4(sfRenderWindow *w, sfEvent ev, struct radar *r, int i);
    char* int_to_str(int n);
    int my_int_length(int n);
    int read_file(char **argv);
    int create_window(char *buffer);
    void display_help(void);
    void choose_pantalla(sfRenderWindow *w, sfEvent ev, struct radar *r);
    void pantalla_inicio(sfRenderWindow *w, sfEvent ev, struct radar *r);
    void pantalla_juego(sfRenderWindow *w, sfEvent ev, struct radar *r);
    void event_click(sfRenderWindow *window, sfEvent event, struct radar *r);
    void conflicto(sfRenderWindow *w, sfEvent ev, struct radar *r, int i);
    int conflicto_2(struct radar *r, int i, int j);
    int zona_radar(sfVector2f a, struct radar *r);
    int f_nospaces(char *buffer, int i);
    int f_spaces(char *buffer, int i);
    int read_pos(struct radar *r, int i);
#endif /*MY_RADAR_H_*/
