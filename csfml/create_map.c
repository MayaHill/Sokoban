/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** object.c
*/

#include "include/bonus_sokoban.h"

void init_map(map_t *map, char **arr_map, char **dup_map)
{
    int len = 0;

    map->max_x = (HEI / 32 - my_strlen_array(arr_map)) / 2;
    map->max_y = 0;
    for (int i = 0; arr_map[i]; i++) {
        len = my_strlen(arr_map[i]);
        if (len > map->max_y)
            map->max_y = len;
    }
    map->max_y = (WID / 32 - map->max_y) / 2;
    map->size_o = 0;
    map->size_t = 0;
    map->moves = 0;
    map->arr_map = arr_map;
    map->dup_map = dup_map;
    for (int x = 0; arr_map[x]; x++)
        for (int y = 0; arr_map[x][y]; y++)
            add_elem(map, arr_map[x][y], x + map->max_x, y + map->max_y);
}

void add_tile(tile_t *tile, char type)
{
    int rand = 0;

    if (type == '#') {
        tile->texture = sfTexture_createFromFile("assets/walls.png", NULL);
        rand = rand_nbr(0, 5);
        tile->rect = (sfIntRect){0, 0, 32, 32};
        tile->type = WALL;
    } else if (type == 'O') {
        tile->texture = sfTexture_createFromFile("assets/objects.png", NULL);
        tile->rect = (sfIntRect){32, 0, 32, 32};
        tile->type = DEST;
    } else {
        tile->texture = sfTexture_createFromFile("assets/floor.png", NULL);
        rand = rand_nbr(3, 6);
        tile->rect = (sfIntRect){rand * 32, 0, 32, 32};
        tile->type = FLOOR;
    }
    sfSprite_setTextureRect(tile->sprite, tile->rect);
    sfSprite_setTexture(tile->sprite, tile->texture, sfTrue);
}

void add_object(tile_t *object, char type)
{
    object->sprite = sfSprite_create();
    if (type == 'X') {
        object->texture = sfTexture_createFromFile("assets/objects.png", NULL);
        object->rect = (sfIntRect){0, 0, 32, 32};
        object->type = BOX;
    }
    if (type == 'P') {
        object->texture = sfTexture_createFromFile("assets/player.png", NULL);
        object->rect = (sfIntRect){0, 0, 32, 32};
        object->type = PLAYER;
    }
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setTextureRect(object->sprite, object->rect);
    sfSprite_setPosition(object->sprite, object->pos);
}

void add_elem(map_t *map, char type, int x, int y)
{
    tile_t tile;
    tile_t object;

    tile.sprite = sfSprite_create();
    tile.pos = (sfVector2f){y * 32, x * 32};
    add_tile(&tile, type);
    if (type == 'X' || type == 'P') {
        object.pos = (sfVector2f){y * 32, x * 32};
        add_object(&object, type);
        map->objects[map->size_o] = object;
        map->size_o += 1;
    }
    sfSprite_setTexture(tile.sprite, tile.texture, sfTrue);
    sfSprite_setTextureRect(tile.sprite, tile.rect);
    sfSprite_setPosition(tile.sprite, tile.pos);
    map->tiles[map->size_t] = tile;
    map->size_t += 1;
}