/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** raytracer.cpp
*/

#include "raytracer.hpp"

Raytracer::Raytracer(std::string file)
{
    this->file = file;
}

Color Raytracer::ray_color(const Ray& r)
{
    load_sphere_library("src/plugins/libsphere.so");
    load_cylinder_library("src/plugins/libcylinder.so");

    auto sphere = create_sphere_instance(Point(-5, 0, -4), 0.5, Color(11, 0, 255));
    auto cylinder = create_cylinder_instance(Point(0, 0, -4), Vector(0, 1, 0), 0.5, 1.0, Color(255, 0, 0));

    Intersection sphere_intersection, cylinder_intersection;

    bool sphere_hit = sphere->intersect(r, sphere_intersection);
    bool cylinder_hit = cylinder->intersect(r, cylinder_intersection);

    if (sphere_hit && (!cylinder_hit || sphere_intersection.getT() < cylinder_intersection.getT())) {
        return sphere_intersection.getColor() / 255;
    } else if (cylinder_hit) {
        printf("cylinder\n");
        return cylinder_intersection.getColor() / 255;
    } else {
        Vector unit_direction = unit_vector(r.direction());
        double t = 0.5 * (unit_direction.y + 1.0);
        return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
    }
}

void Raytracer::run()
{
    this->image_width = 600;
    double aspect_ratio = 16.0 / 9.0;
    image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;
    image = std::vector<std::vector<Color>>(image_height, std::vector<Color>(image_width));
    this->_window.create(sf::VideoMode(image_width, image_height), "raytracer");
    vertices = create_map();

    while (this->_window.isOpen())
        WindowLoop();
    save_ppm();
}