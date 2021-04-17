/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** update_game.c
*/

#include "include/bonus_sokoban.h"

void destroy_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

void update_game(window_t *win, map_t *map)
{
    char *seconds = to_str(get_seconds(win->clock));
    char *moves = to_str(map->moves);
    char *time = my_strcat("Time : ", seconds);

    moves = my_strcat("Moves: ", moves);
    update_objects(win->window, map);
    sfRenderWindow_clear(win->window, sfBlack);
    show_map(win->window, map);
    display_buttons(win->window, &map->buttons, map->var);
    draw_text(win, time);
    sfText_setPosition(win->text, (sfVector2f){WID - 288, 96});
    draw_text(win, moves);
    sfText_setPosition(win->text, (sfVector2f){WID - 288, 32});
    free(time);
    free(seconds);
    free(moves);
}

void update_window(window_t *win, map_t *map)
{
    int status = game_won(map->arr_map, map->dup_map);
    char *message = NULL;

    if (status != 2) {
        if (status == 1)
            message = "You lose!";
        else
            message = "You win!";
        sfRenderWindow_clear(win->window, sfBlack);
        display_buttons(win->window, &map->buttons, map->var);
        draw_text(win, message);
        sfText_setPosition(win->text, (sfVector2f){800, 500});
    } else
        update_game(win, map);
    sfRenderWindow_display(win->window);
}

void update_menu(window_t *win, map_t *map)
{
    update_objects(win->window, map);
    sfRenderWindow_clear(win->window, sfBlack);
    show_map(win->window, map);
    display_buttons(win->window, &map->buttons, map->var);
    sfRenderWindow_display(win->window);
    sfClock_restart(win->clock);
    map->moves = 0;
    destroy_array(map->arr_map);
    map->arr_map = duplicate_map(map->dup_map);
}