/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <SFML/Graphics.h>
    #include <stdio.h>
    #include <time.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <SFML/Audio.h>
    #include <unistd.h>

typedef struct duck{
    sfVector2f pos_duck;
    int width;
    int height;
    sfIntRect rect;
    sfTexture* texture_duck;
    sfSprite* sprite_duck;
    sfClock *clock_rec;
    sfClock *clock_mov;
} duck;
typedef struct heart{
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    int height;
    int width;
}heart;
typedef struct crosshair{
    sfTexture *text_ch;
    sfSprite *sprite_ch;
    sfVector2f pos_mouse;
    sfVector2i pos;
}crosshair;
typedef struct background{
    sfTexture *text;
    sfSprite *sprite;
}background;
typedef struct music{
    sfMusic *music;
}music;
struct duck *create_duck(void);
void move_pos(sfClock *, struct duck *);
void anim_duck(struct duck *, int, int, sfClock *);
void hitbox_duck(struct duck *, sfVector2i);
int h_flag(int , char **, sfRenderWindow *);
struct music create_music(void);
void respawn(struct duck *);
void manage_life(sfRenderWindow *, struct duck *, heart *);
struct heart create_heart(void);
void destroy_sprite_text_struct(heart , duck *, crosshair, background);
struct crosshair create_crosshair(void);
struct background create_background(void);
struct background create_game_over(void);
void manage_ch(sfRenderWindow *, crosshair *);
void destroy_clock_x2(sfClock *, sfClock *);

#endif /* MY_H_ */
