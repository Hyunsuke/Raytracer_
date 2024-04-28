/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** raytracer.cpp
*/

#include "core/raytracer.hpp"

Raytracer::Raytracer(char *file)
{
    this->file = file;
}

Raytracer::~Raytracer()
{
}

void Raytracer::run()
{
    std::cout << "Running raytracer" << std::endl;
}