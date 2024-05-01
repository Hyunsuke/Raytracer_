/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** sphere.cpp
*/

#include "raytracer.hpp"

void Raytracer::load_sphere_library()
{
    handle = dlopen("src/libs/libsphere.so", RTLD_LAZY);
    if (!handle) {
        throw RaytracerException("Failed to load Sphere library", "Library");
    }
}

std::unique_ptr<Primitive<Sphere>> Raytracer::create_sphere_instance(const Point& center, double radius, const Color& color)
{
    if (!handle)
        throw RaytracerException("Failed to create Sphere instance", "Function");

    using CreateSphereFunc = std::unique_ptr<Primitive<Sphere>> (*)(const Point&, double, const Color&);
    CreateSphereFunc create_sphere = reinterpret_cast<CreateSphereFunc>(dlsym(handle, "create_sphere"));
    if (!create_sphere)
        throw RaytracerException("Failed to create Sphere instance", "Function");

    return create_sphere(center, radius, color);
}
