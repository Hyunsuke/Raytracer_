/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** cylinder.cpp
*/

#include "raytracer.hpp"

void Raytracer::load_cylinder_library(const std::string& libraryPath)
{
    cylinderLibraryLoader.loadLibrary(libraryPath);
}

std::unique_ptr<Cylinder> Raytracer::create_cylinder_instance(const Point& center, const Vector& axis, double radius, double height, const Color& color, const Vector& rotation_axis, double rotation_angle_deg)
{
    auto create_cylinder = cylinderLibraryLoader.getFunction("create_cylinder");
    return std::unique_ptr<Cylinder>(create_cylinder(center, axis, radius, height, color, rotation_axis, rotation_angle_deg));
}