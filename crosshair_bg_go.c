/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** open a window with the background
*/

#include "include/my.h"

struct crosshair create_crosshair(void)
{
    struct crosshair crosshair;

    crosshair.text_ch = sfTexture_createFromFile("png/ch.png", NULL);
    crosshair.sprite_ch = sfSprite_create();
    sfSprite_setTexture(crosshair.sprite_ch, crosshair.text_ch, sfTrue);
    return crosshair;
}

void manage_ch(sfRenderWindow *window, crosshair *crosshair)
{
    crosshair->pos_mouse = (sfVector2f){crosshair->pos.x, crosshair->pos.y};
    crosshair->pos = sfMouse_getPositionRenderWindow(window);
    sfSprite_setPosition(crosshair->sprite_ch, crosshair->pos_mouse);
    sfRenderWindow_drawSprite(window, crosshair->sprite_ch, NULL);
}

struct background create_background(void)
{
    struct background background;

    background.text = sfTexture_createFromFile("png/bg.png", NULL);
    background.sprite = sfSprite_create();
    sfSprite_setTexture(background.sprite, background.text, sfTrue);
    return background;
}

struct background create_game_over()
{
    struct background game_over;
    sfVector2f pos = {500.0f, 250.0f};

    game_over.text = sfTexture_createFromFile("png/game_over.png", NULL);
    game_over.sprite = sfSprite_create();
    sfSprite_setTexture(game_over.sprite, game_over.text, sfTrue);
    sfSprite_setPosition(game_over.sprite, pos);
    return game_over;
}
