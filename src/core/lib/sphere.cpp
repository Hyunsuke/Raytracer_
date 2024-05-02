/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** sphere.cpp
*/

#include "raytracer.hpp"

void Raytracer::load_sphere_library(const std::string& libraryPath)
{
    sphereLibraryLoader.loadLibrary(libraryPath);
}

std::unique_ptr<Primitive<Sphere>> Raytracer::create_sphere_instance(const Point& center, double radius, const Color& color) {
    auto create_sphere = sphereLibraryLoader.getFunction("create_sphere");
    return create_sphere(center, radius, color);
}
