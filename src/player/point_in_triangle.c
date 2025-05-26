/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** point_in_triangle.c
*/

#include <SFML/System/Vector2.h>
#include <stdbool.h>

bool point_in_triangle(sfVector2f point, sfVector2f a,
    sfVector2f b, sfVector2f c)
{
    float denominator = ((b.y - c.y) * (a.x - c.x) +
            (c.x - b.x) * (a.y - c.y));
    float alpha = ((b.y - c.y) * (point.x - c.x) +
            (c.x - b.x) * (point.y - c.y)) / denominator;
    float beta = ((c.y - a.y)*(point.x - c.x) +
            (a.x - c.x)*(point.y - c.y)) / denominator;
    float gamma = 1.0 - alpha - beta;

    return (alpha >= 0) && (beta >= 0) &&
            (gamma >= 0) && (alpha <= 1) &&
            (beta <= 1) && (gamma <= 1);
}
