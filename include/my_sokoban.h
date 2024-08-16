/*
** EPITECH PROJECT, 2022
** my_sokoban.h
** File description:
** .h
*/

#ifndef MY_SOKOBAN_H_
    #define MY_SOKOBAN_H_
    #include "my.h"
    #include <ncurses.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <stdlib.h>
    #define MAXBUF 2000000
    struct map {
        char **map;
        int no_mover;
        int *col;
        int filas;
        int pos_i;
        int pos_j;
        int num_o;
        int num_x;
        int pos_ox;
        int pos_oy;
        int numdeoconx;
        int *posdeoconx_x;
        int *posdeoconx_y;
    };
    void key_dch(int key, struct map *mp);
    int switch_valid (char a);
    int bucle(char *buffer);
    int see_ifvalid(char *buffer);
    void my_help_sokoban(void);
    int my_sokoban_open(char *fpath);
    int pos_function(int key, struct map *mp);
    void print_mapa(struct map *mp);
    void switch_function(char pos, int i, int j);
    void create_map(char *buffer, struct map *m);
    int enc_p(struct map *m, int i, int j);
    void read_buffer(char *buffer, struct map *m);
    void pos_save_o_up(struct map *mp);
    void pos_o_up(struct map *mp);
    void pos_x_up(struct map *mp);
    void pos_save_o_down(struct map *mp);
    void pos_o_down(struct map *mp);
    void pos_x_down(struct map *mp);
    void pos_save_o_left(struct map *mp);
    void pos_o_left(struct map *mp);
    void pos_x_left(struct map *mp);
    void pos_save_o_right(struct map *mp);
    void pos_o_right(struct map *mp);
    void pos_x_right(struct map *mp);
    int comprobar_ox(struct map *m, int i, int j);
    void up_fun(struct map *mp);
    void down(struct map *mp);
    void left(struct map *mp);
    void right(struct map *mp);
    int num_filas(char *buffer);
    int num_col(char *buffer, struct map *m);
    int key_pressed(int key, struct map *mp);
    int key_up(int key, struct map *mp);
    int key_down(int key, struct map *mp);
    int key_left(int key, struct map *mp);
    int key_right(int key, struct map *mp);
    void ver_pos_xo(struct map *m);
    void function_o(struct map *m, int i, int j);
    void function_x(struct map *m, int i, int j);
#endif /*MY_SOKOBAN_H_*/
