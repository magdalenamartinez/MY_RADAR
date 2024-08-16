/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "../include/my_radar.h"
int main(int argc, char **argv)
{
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            display_help();
        } else {
            int n = read_file(argv);
            return n;
        }
    } else {
        return 84;
    }
}

int read_file(char **argv)
{
    int file = 0;
    file = open(argv[1], O_RDONLY);
    if (file == -1) {
        return 84;
    } else {
        char buffer[MAXBUFFER] = "NULL";
        int len = 0; int offset = 0;
        while ((len = read(file, buffer + offset, MAXBUFFER - offset)) > 0) {
            offset += len;
        }
        buffer[offset] = '\0'; close(file);
        create_window(buffer);
    }
}

void display_help(void)
{
    my_printf("Air traffic simulation panel\n\n");
    my_printf("USAGE\n");
    my_printf("./my_radar[OPTIONS] path_to_script\n");
    my_printf("path_to_script   The path to the script file.\n\n");
    my_printf("OPTIONS\n");
    my_printf("-h               print the usage and quit.\n\n");
    my_printf("USER INTERACTIONS\n");
    my_printf("'L' key      enable/disable hitboxes and areas.\n");
    my_printf("'S' key      enable/disable sprites.\n");

}

int create_window(char *buffer)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, "My Radar", sfClose, NULL);
    if (!window) {
        return 84;
    } else {
        sfEvent event;
        function_createsprites(window, event, buffer);
    }
}
