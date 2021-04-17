/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** sokoban.h
*/

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <math.h>
#include "../../include/my.h"
#include "../../include/my_printf.h"
#include "framebuffer.h"

typedef enum {
    WALL,
    FLOOR,
    BOX,
    DEST,
    PLAYER
} my_type;

typedef struct var_s {
    int quit;
    int play;
} var_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfTexture *inactive;
    sfTexture *hover;
    sfSprite *sprite;
    void (*ptr)(var_t *var);
} button_t;

typedef struct buttons_s {
    button_t all[10];
    int size;
} buttons_t;

typedef struct tile_s {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    my_type type;
    sfVector2f pos;
} tile_t;

typedef struct map_s {
    tile_t tiles[1000];
    tile_t objects[20];
    buttons_t buttons;
    var_t var;
    int size_t;
    int size_o;
    char **arr_map;
    char **dup_map;
    int max_x;
    int max_y;
    int moves;
} map_t;

void destroy_array(char **array);

void print_map(char **map);

int end_loop(int status, char **map, char **dup_map);

void add_object(tile_t *object, char type);

void show_map(sfRenderWindow *win, map_t *map);

void update_objects(sfRenderWindow *win, map_t *map);

void destroy_map(map_t *map);

void analyse_events(window_t *win, map_t *map);

sfRenderWindow *create_window(void);

void destroy_window(window_t *win, map_t *map);

sfText *create_text(sfText *text, sfVector2f pos, sfFont *font);

void draw_text(window_t *win, char *str);

void init_map(map_t *map, char **arr_map, char **dup_map);

void add_elem(map_t *map, char type, int x, int y);

int *get_index(char **map, char c);

char **duplicate_map(char **map);

int walkable(char c);

int check_map_error(char *str);

int game_won(char **map, char **dup_map);

void move_player(map_t *my_map, int x, int y);

void get_move_action(char c, char **dup_map, char **map);

char *read_file(char *filepath);

int my_strlen_array(char **array);

void print_map(char **map);

int print_help(void);

void init_tiles(char **arr_map);

void update_game(window_t *win, map_t *map);

void update_window(window_t *win, map_t *map);

void update_menu(window_t *win, map_t *map);

// Buttons

void create_buttons_array(buttons_t *buttons);

void add_graphics(char *inactive, char *hover, button_t *button);

void add_button(buttons_t *buttons, sfVector2f pos, void (*ptr)(var_t *var));

void display_buttons(sfRenderWindow *window, buttons_t *obj_array, var_t var);

void destroy_buttons(buttons_t *obj_array);

// Button functions

void play_button(var_t *var);

void quit_button(var_t *var);

void back_button(var_t *var);