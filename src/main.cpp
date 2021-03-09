/*
** EPITECH PROJECT, 2020
** CNA
** File description:
** main
*/

#include "../include/Groundhog.hpp"

int main(int ac, char **av)
{
    Groundhog groundhog;
    if (ac != 2)
        return (84);
    if (std::atoi(av[1]) < 1)
        return (84);
    groundhog.core(std::atoi(av[1]));
    return (0);
}
