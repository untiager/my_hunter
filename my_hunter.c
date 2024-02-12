/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** open a window with the background
*/

#include "include/my.h"

void handle_event(sfEvent *event, sfRenderWindow *window, struct duck *duck1)
{
    sfVector2i pos;
    sfSoundBuffer* gunshot_buffer;
    sfSound* gunshot;

    pos = sfMouse_getPositionRenderWindow(window);
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed || event->type == sfEvtKeyPressed)
            sfRenderWindow_close(window);
        if (event->type == sfEvtMouseButtonPressed) {
            gunshot = sfSound_create();
            gunshot_buffer = sfSoundBuffer_createFromFile("sound/gunshot.ogg");
            sfSound_setBuffer(gunshot, gunshot_buffer);
            sfSound_play(gunshot);
            hitbox_duck(duck1, pos);
        }
    }
}

sfRenderWindow *create_window(int ac, char **av)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = 1920;
    video_mode.height = 1080;
    window = sfRenderWindow_create(video_mode, "hunter", sfDefaultStyle, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setFramerateLimit(window, 120);
    h_flag(ac, av, window);
    return window;
}

int main(int ac, char **av)
{
    sfRenderWindow *window = create_window(ac, av);
    sfEvent event;
    duck *duck1 = create_duck();
    heart heart = create_heart();
    crosshair crosshair = create_crosshair();
    background background = create_background();
    music music = create_music();

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, background.sprite, NULL);
        anim_duck(duck1, 110, 220, duck1->clock_rec);
        sfRenderWindow_drawSprite(window, duck1->sprite_duck, NULL);
        manage_ch(window, &crosshair);
        manage_life(window, duck1, &heart);
        handle_event(&event, window, duck1);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music.music);
    sfRenderWindow_destroy(window);
    destroy_sprite_text_struct(heart, duck1, crosshair, background);
}
