/*
** EPITECH PROJECT, 2020
** IntroCSFML
** File description:
** framebuffer.h
*/

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include <SFML/Graphics.h>

static int WID = 1920;
static int HEI = 1080;

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};

typedef struct framebuffer framebuffer_t;

typedef struct window_s {
    sfRenderWindow *window;
    framebuffer_t *buffer;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfText *text;
} window_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);

void framebuffer_destroy(framebuffer_t *framebuffer);

void my_put_pixel(framebuffer_t *b, unsigned int x, unsigned int y, sfColor);

void my_draw_square (framebuffer_t *, sfVector2u, unsigned int, sfColor);

int draw_outline_circle(framebuffer_t *buff, sfVector2i center, int radius);

int draw_line(framebuffer_t *buff, sfVector2i point_a, sfVector2i point_b);

void reset_framebuffer_to_color(framebuffer_t *framebuffer, sfColor color);

int rand_nbr(int lower, int upper);

float get_seconds(sfClock *clock);

#endif /* FRAMEBUFFER_H_ */