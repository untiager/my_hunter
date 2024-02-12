/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** flag h for my_hunter
*/

#include "include/my.h"

int h_flag(int argc, char **argv, sfRenderWindow *window)
{
    if (argc == 2){
        if (argv[1][0] == '-' && argv[1][1] == 'h'){
            write(1, "shoot the duck before they reach the border\n", 45);
            write(1, "press any key or close the window to exit\n", 43);
            sfRenderWindow_close(window);
        }
    }
}
