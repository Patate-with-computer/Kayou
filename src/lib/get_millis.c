/*
** EPITECH PROJECT, 2024
** opne
** File description:
** open
*/

#include <SFML/Graphics.h>

float get_millis(sfClock *clock)
{
    return (float)sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
}
