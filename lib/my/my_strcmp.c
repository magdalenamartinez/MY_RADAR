/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** compare 2 strings
*/
#include <stdio.h>
int my_strcmp(char const *s1, char const *s2)
{
    int fin = 0; int i = 0; int fin2 = 0;
    while (s1[fin] != '\0') {
        fin++;
    }
    while (s1[i] == s2[i]) {
        i++;
    }
    i--;
    if (i == fin) {
        return 0;
    } else {
        while (s2[fin2] != '\0') {
            fin2++;
        }
        if (fin >= fin2) {
            return 1;
        } else {
            return -1;
        }
    }
}
/*
int main()
{
    int i = 0;
    char a[ ]="hell";
    char b[ ]="h";
    int n=my_strcmp(a,b);
    if(n==0){
        printf("iguales");
    }else if(n<0){
        printf("s1 es menor");
    }else{printf("s1 es mayor");}
    return 0;
}
*/
