/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** main.c
*/

#include "include/bonus_sokoban.h"

int end_loop(int status, char **map, char **dup_map)
{
    for (int i = 0; map[i]; i++) {
        free(map[i]);
        free(dup_map[i]);
    }
    free(map);
    free(dup_map);
    return (status);
}

void main_loop(window_t *win, map_t *map)
{
    sfClock *clock = sfClock_create();
    char *moves = my_strcat("Moves : ", to_str(map->moves));

    while (!map->var.quit && sfRenderWindow_isOpen(win->window)) {
        analyse_events(win, map);
        if (map->var.play == 1 && get_seconds(clock) > 0.05) {
            update_window(win, map);
            sfClock_restart(clock);
        }
        if (map->var.play == 0 && get_seconds(clock) > 0.05) {
            update_menu(win, map);
            sfClock_restart(clock);
        }
    }
    sfClock_destroy(clock);
}

void init_tiles(char **arr_map)
{
    char **dup_map = duplicate_map(arr_map);
    window_t win;
    sfFont *font = sfFont_createFromFile("assets/FFFFORWA.TTF");
    map_t map;

    init_map(&map, arr_map, dup_map);
    map.var.quit = 0;
    map.var.play = 0;
    create_buttons_array(&map.buttons);
    win.text = create_text(win.text, (sfVector2f){WID - 288, 32}, font);
    win.clock = sfClock_create();
    win.window = create_window();
    win.buffer = framebuffer_create(WID, HEI);
    sfText_setString(win.text, "Time : 0");
    main_loop(&win, &map);
    end_loop(0, map.arr_map, map.dup_map);
    sfFont_destroy(font);
    destroy_window(&win, &map);
}
