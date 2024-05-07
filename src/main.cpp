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
        check_and_parse parsed(ac, av[1]);
        // std::vector<std::pair<std::string, int>> test;
        // test = parsed.getCameraResolution();

        Raytracer raytracer(av[1], parsed);
        raytracer.run();
    } catch (const RaytracerException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}