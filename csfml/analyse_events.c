/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** analyse_events.c
*/

#include "include/bonus_sokoban.h"

void edit_under_player(char **dup_map, char **map, int *save)
{
    map[save[0]][save[1]] = ' ';
    if (dup_map[save[0]][save[1]] == 'O')
        map[save[0]][save[1]] = 'O';
}

void move_player(map_t *my_map, int x, int y)
{
    char **map = my_map->arr_map;
    char **dup_map = my_map->dup_map;
    int *player = get_index(map, 'P');

    if (map[player[0] + x][player[1] + y] == 'X') {
        if (walkable(map[player[0] + x * 2][player[1] + y * 2])) {
            my_map->moves += 1;
            edit_under_player(dup_map, map, player);
            map[player[0] + x][player[1] + y] = 'P';
            map[player[0] + x * 2][player[1] + y * 2] = 'X';
        }
    } else if (walkable(map[player[0] + x][player[1] + y])) {
        my_map->moves += 1;
        edit_under_player(dup_map, map, player);
        map[player[0] + x][player[1] + y] = 'P';
    }
    free(player);
}

int button_is_clicked(button_t button, sfVector2f mouse_pos)
{
    sfVector2f b_pos = sfRectangleShape_getPosition(button.rect);
    sfVector2f b_size = sfRectangleShape_getSize(button.rect);

    if (mouse_pos.x >= b_pos.x && mouse_pos.x <= b_pos.x + b_size.x)
        if (mouse_pos.y >= b_pos.y && mouse_pos.y <= b_pos.y + b_size.y)
            return (1);
    return (0);
}

void check_buttons(sfRenderWindow *window, buttons_t *buttons, var_t *var)
{
    sfVector2i int_mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_pos = (sfVector2f){int_mouse_pos.x, int_mouse_pos.y};
    sfBool pressed = sfMouse_isButtonPressed(sfMouseLeft);
    button_t button;
    int hover = 0;

    for (int i = 0; i < buttons->size; i++) {
        button = buttons->all[i];
        hover = button_is_clicked(button, mouse_pos);
        if (pressed && hover) {
            button.ptr(var);
        } else if (hover) {
            sfSprite_setTexture(button.sprite, button.hover, sfTrue);
        } else {
            sfSprite_setTexture(button.sprite, button.inactive, sfTrue);
        }
    }
}

void analyse_events(window_t *win, map_t *map)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win->window, &event)) {
        check_buttons(win->window, &map->buttons, &map->var);
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win->window);
        if (map->var.play && sfKeyboard_isKeyPressed(sfKeyUp))
            move_player(map, -1, 0);
        if (map->var.play && sfKeyboard_isKeyPressed(sfKeyDown))
            move_player(map, 1, 0);
        if (map->var.play && sfKeyboard_isKeyPressed(sfKeyLeft))
            move_player(map, 0, -1);
        if (map->var.play && sfKeyboard_isKeyPressed(sfKeyRight))
            move_player(map, 0, 1);
        if (map->var.play && sfKeyboard_isKeyPressed(sfKeySpace)) {
            sfClock_restart(win->clock);
            map->moves = 0;
            destroy_array(map->arr_map);
            map->arr_map = duplicate_map(map->dup_map);
        }
    }
}