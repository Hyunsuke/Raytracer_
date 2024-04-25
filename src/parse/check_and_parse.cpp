/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** check_and_parse.cpp
*/

#include "raytracer.hpp"

void print_usage()
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>\n" << std::endl;
    std::cout << "\tSCENE_FILE: scene configuration" << std::endl;
}

check_and_parse::check_and_parse(int ac, char **av)
{
    if (ac != 2) {
        throw RaytracerException("Invalid number of arguments, --help for information", "check_and_parse");
    }
    if (ac == 2 && std::string(av[1]) == "--help") {
        print_usage();
        exit(0);
    }
}