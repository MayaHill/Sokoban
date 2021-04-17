/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** object.c
*/

#include "include/bonus_sokoban.h"

void show_map(sfRenderWindow *win, map_t *map)
{
    for (int i = 0; i < map->size_t; i++) {
        sfRenderWindow_drawSprite(win, map->tiles[i].sprite, NULL);
    }
    for (int i = 0; i < map->size_o; i++) {
        sfRenderWindow_drawSprite(win, map->objects[i].sprite, NULL);
    }
}

void update_elem(map_t *map, char type, int x, int y)
{
    tile_t object;

    if (type == 'X' || type == 'P') {
        object.pos = (sfVector2f){y * 32, x * 32};
        add_object(&object, type);
        map->objects[map->size_o] = object;
        map->size_o += 1;
    }
}

void update_objects(sfRenderWindow *win, map_t *map)
{
    int max_x = map->max_x;
    int max_y = map->max_y;

    for (int i = 0; i < map->size_o; i++) {
        sfTexture_destroy(map->objects[i].texture);
        sfSprite_destroy(map->objects[i].sprite);
    }
    map->size_o = 0;
    for (int x = 0; map->arr_map[x]; x++)
        for (int y = 0; map->arr_map[x][y]; y++)
            update_elem(map, map->arr_map[x][y], max_x + x, max_y + y);
}

void destroy_map(map_t *map)
{
    for (int i = 0; i < map->size_o; i++) {
        sfTexture_destroy(map->objects[i].texture);
        sfSprite_destroy(map->objects[i].sprite);
    }
    for (int i = 0; i < map->size_t; i++) {
        sfTexture_destroy(map->tiles[i].texture);
        sfSprite_destroy(map->tiles[i].sprite);
    }
}