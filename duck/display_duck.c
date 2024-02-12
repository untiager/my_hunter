/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#include "../include/my.h"

struct duck *create_duck(void)
{
    struct duck *duck1;

    duck1 = malloc(sizeof(duck));
    srand(time(0));
    duck1->pos_duck.x = 0;
    duck1->pos_duck.y = rand() % 500;
    duck1->rect = (sfIntRect){0, 0, 110, 110};
    duck1->height = 110;
    duck1->width = 110;
    duck1->texture_duck = sfTexture_createFromFile("png/sps.png", NULL);
    duck1->sprite_duck = sfSprite_create();
    duck1->clock_mov = sfClock_create();
    duck1->clock_rec = sfClock_create();
    sfSprite_setTexture(duck1->sprite_duck, duck1->texture_duck, sfTrue);
    sfSprite_setTextureRect(duck1->sprite_duck, duck1->rect);
    sfSprite_setPosition(duck1->sprite_duck, duck1->pos_duck);
    return duck1;
}

void anim_duck(struct duck *duck1, int offset,
    int max_value, sfClock *clock_rec)
{
    sfTime time = sfClock_getElapsedTime(clock_rec);
    float seconds = time.microseconds / 1000000.0;

    if (seconds >= 0.3) {
        if (duck1->rect.left < max_value){
            duck1->rect.left += offset;
            sfSprite_setTextureRect(duck1->sprite_duck, duck1->rect);
            sfClock_restart(clock_rec);
        } else {
            duck1->rect.left = 0;
            sfSprite_setTextureRect(duck1->sprite_duck, duck1->rect);
            sfClock_restart(clock_rec);
        }
    }
    move_pos(duck1->clock_mov, duck1);
}

void move_pos(sfClock *clock_mov, struct duck *duck1)
{
    sfVector2f vitesse = {10.0f, -0.5f};
    sfTime time = sfClock_getElapsedTime(clock_mov);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.02) {
        duck1->pos_duck.x += vitesse.x;
        duck1->pos_duck.y += vitesse.y;
        sfSprite_setPosition(duck1->sprite_duck, duck1->pos_duck);
        sfClock_restart(clock_mov);
    }
    respawn(duck1);
}

void hitbox_duck(struct duck *duck1, sfVector2i pos)
{
    sfSoundBuffer *hit_duck_buff ;
    sfSound *hit_duck = sfSound_create();

    hit_duck_buff = sfSoundBuffer_createFromFile("sound/hit.ogg");
    if (hit_duck_buff == NULL){
        write(1, "error with opening sound file\n", 31);
    }
    sfSound_setBuffer(hit_duck, hit_duck_buff);
    if (pos.x >= duck1->pos_duck.x
    && pos.y >= duck1->pos_duck.y
    && pos.x <= (duck1->pos_duck.x + duck1->width)
    && pos.y <= (duck1->pos_duck.y + duck1->height)){
        sfSound_play(hit_duck);
        duck1->pos_duck.x = -100;
        duck1->pos_duck.y = rand() % 500;
        sfSprite_setPosition(duck1->sprite_duck, duck1->pos_duck);
    }
}

void respawn(struct duck *duck1)
{
    if (duck1->pos_duck.x >= 1920){
        duck1->pos_duck.x = -100;
        duck1->pos_duck.y = rand() % 500;
        sfSprite_setPosition(duck1->sprite_duck, duck1->pos_duck);
    }
}
