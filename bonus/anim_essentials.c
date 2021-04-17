/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** anim1-essentials.c
*/

#include "include/bonus_sokoban.h"

void reset_framebuffer_to_color(framebuffer_t *framebuffer, sfColor color)
{
    for (int x = 0; x < WID; x++)
        for (int y = 0; y < HEI; y++)
            my_put_pixel(framebuffer, x, y, color);
}

int rand_nbr(int lower, int upper)
{
    int nbr = (rand() % (upper - lower + 1)) + lower;

    return (nbr);
}

float get_seconds(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    return (seconds);
}

int my_strlen_array(char **array)
{
    int len = 0;

    for (; array[len]; len++);
    return (len);
}