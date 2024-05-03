/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** cone.cpp
*/

#include "raytracer.hpp"

void Raytracer::load_cone_library(const std::string& libraryPath)
{
    coneLibraryLoader.loadLibrary(libraryPath);
}

std::unique_ptr<Cone> Raytracer::create_cone_instance(const Point& apex, const Vector& axis_direction, double angle, double height, const Color& color)
{
    auto create_cone = coneLibraryLoader.getFunction("create_cone");
    return create_cone(apex, axis_direction, angle, height, color);
}