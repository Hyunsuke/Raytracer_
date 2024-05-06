/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** plane.cpp
*/

#include "raytracer.hpp"

void Raytracer::load_plane_library(const std::string& libraryPath)
{
    planeLibraryLoader.loadLibrary(libraryPath);
}

std::unique_ptr<Plane> Raytracer::create_plane_instance(const char axis, double position, const Color& color) {
    auto create_plane = planeLibraryLoader.getFunction("create_plane");
    return std::unique_ptr<Plane>(create_plane(axis, position, color));
}