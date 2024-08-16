/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** funcion which
*/

#include <stdio.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
/*
int main (void){
    char *src = "Hello";
    char *dest;
    printf("%s\n", my_strcpy(dest, src));
}
*/
