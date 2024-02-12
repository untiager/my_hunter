/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** open a window with the background
*/

#include "include/my.h"

struct music create_music(void)
{
    struct music music;

    music.music = sfMusic_createFromFile("sound/music.ogg");
    sfMusic_setLoop(music.music, true);
    sfMusic_play(music.music);
    return music;
}
