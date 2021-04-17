/*
** EPITECH PROJECT, 2020
** My_Defender
** File description:
** button_functions.c
*/

#include "include/bonus_sokoban.h"

void play_button(var_t *var)
{
    var->play = 1;
}

void back_button(var_t *var)
{
    var->play = 0;
}

void quit_button(var_t *var)
{
    var->quit = 1;
}