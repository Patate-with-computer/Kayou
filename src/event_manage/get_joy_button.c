/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_joy_button.c
*/

#include <SFML/Graphics.h>
#include <stdio.h>

sfBool get_joy_button(size_t nb_joy, size_t button)
{
    if (sfJoystick_isConnected(nb_joy)) {
        return sfJoystick_isButtonPressed(nb_joy, button);
    }
    return sfFalse;
}
