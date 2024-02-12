/*
** EPITECH PROJECT, 2023
** destroy.c
** File description:
** the file to destroy everything
*/

#include "include/my.h"

void destroy_sprite_text_struct(heart heart, duck *duck1,
    crosshair crosshair, background background)
{
    sfTexture_destroy(duck1->texture_duck);
    sfSprite_destroy(duck1->sprite_duck);
    sfTexture_destroy(heart.texture);
    sfSprite_destroy(heart.sprite);
    sfTexture_destroy(crosshair.text_ch);
    sfSprite_destroy(crosshair.sprite_ch);
    sfTexture_destroy(background.text);
    sfSprite_destroy(background.sprite);
    sfClock_destroy(duck1->clock_mov);
    sfClock_destroy(duck1->clock_rec);
}
