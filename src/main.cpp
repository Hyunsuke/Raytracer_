/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** main.cpp
*/

#include "core/raytracer.hpp"
#include "core/check_and_parse.hpp"

int main(int ac, char **av)
{
    try {
        check_and_parse check_and_parse(ac, av);

        Raytracer raytracer(av[1]);
        raytracer.run();
    } catch (const RaytracerException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}