/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** open a window with the background
*/

#include "include/my.h"


struct heart create_heart(void)
{
    struct heart heart;
    sfVector2f pos_heart = {0.0f, 0.0f};

    heart.height = 70;
    heart.width = 323;
    heart.rect = (sfIntRect){0, 0, 323, 70};
    heart.texture = sfTexture_createFromFile("png/heart.png", NULL);
    heart.sprite = sfSprite_create();
    sfSprite_setTexture(heart.sprite, heart.texture, sfTrue);
    sfSprite_setTextureRect(heart.sprite, heart.rect);
    sfSprite_setPosition(heart.sprite, pos_heart);
    return heart;
}

void manage_life(sfRenderWindow *window, duck *duck1, heart *heart)
{
    background game_over = create_game_over();


    if (duck1->pos_duck.x >= 1910 && heart->rect.top < 300){
        heart->rect.top += 27;
        sfSprite_setTextureRect(heart->sprite, heart->rect);
    }
    if (heart->rect.top >= 300){
        sfRenderWindow_drawSprite(window, game_over.sprite, NULL);
        //sfRenderWindow_close(window);
    }
    sfRenderWindow_drawSprite(window, heart->sprite, NULL);
}
