/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** sokoban.h
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int get_longest_line(char **array);

int *get_index(char **map, char c);

char **duplicate_map(char **map);

int walkable(char c);

int check_map_error(char *str);

int game_won(char **map, char **dup_map);

void move_player(char **map, char **dup_map, int x, int y);

void get_move_action(char c, char **dup_map, char **map);

char *read_file(char *filepath);

int my_strlen_array(char **array);

void print_map(char **map);