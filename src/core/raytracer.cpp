/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** raytracer.cpp
*/

#include "raytracer.hpp"

Raytracer::Raytracer(char *file)
{
    this->file = file;
}

Raytracer::~Raytracer()
{
}

double hit_sphere(const Point& center, double radius, const Ray& r)
{
    Vector oc = center - r.origin();
    auto a = dot(r.direction(), r.direction());
    auto b = -2.0 * dot(r.direction(), oc);
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;

    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - sqrt(discriminant) ) / (2.0*a);
    }
}

Color Raytracer::ray_color(const Ray& r)
{
    auto t1 = hit_sphere(Point(0,0,-1), 0.5, r);
    if (t1 > 0.0) {
        Vector N = unit_vector(r.at(t1) - Vector(0,0,-1));
        return 0.5*Color(N.x+1, N.y+1, N.z+1);
    }

    Vector unit_direction = unit_vector(r.direction());
    auto t2 = 0.5 * (unit_direction.y + 1.0);
    return (1.0 - t2) * Color(1.0, 1.0, 1.0) + t2 * Color(0.5, 0.7, 1.0);
}

void Raytracer::run()
{
    this->image_width = 800;
    auto aspect_ratio = 16.0 / 9.0;
    image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;
    image = std::vector<std::vector<Color>>(image_height, std::vector<Color>(image_width));
    this->_window.create(sf::VideoMode(image_width, image_height), "raytracer");

    while (this->_window.isOpen())
        WindowLoop();
}