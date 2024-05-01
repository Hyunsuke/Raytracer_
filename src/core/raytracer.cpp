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

void Raytracer::load_sphere_library() {
    handle = dlopen("src/libs/libsphere.so", RTLD_LAZY);
    if (!handle) {
        throw RaytracerException("Failed to load Sphere library", "Library");
    }
}

std::unique_ptr<Primitive<Sphere>> Raytracer::create_sphere_instance(const Point& center, double radius) {
    if (!handle) {
        throw RaytracerException("Failed to create Sphere instance", "Function");
    }

    using CreateSphereFunc = std::unique_ptr<Primitive<Sphere>> (*)(const Point&, double);
    CreateSphereFunc create_sphere = reinterpret_cast<CreateSphereFunc>(dlsym(handle, "create_sphere"));
    if (!create_sphere) {
        throw RaytracerException("Failed to create Sphere instance", "Function");
    }
    return create_sphere(center, radius);
}

Color Raytracer::ray_color(const Ray& r) {
    try {
        load_sphere_library();

        auto sphere = create_sphere_instance(Point(0, 0, -1), 0.5);

        double t_val = 0.0;
        Point pos;
        Vector norm;
        Color col;

        Intersection intersection(t_val, pos, norm, col);
        if (sphere->intersect(r, intersection)) {
            Vector N = unit_vector(intersection.normal);
            return 0.5 * Color(N.x + 1, N.y + 1, N.z + 1);
        } else {
            Vector unit_direction = unit_vector(r.direction());
            double t2 = 0.5 * (unit_direction.y + 1.0);
            return (1.0 - t2) * Color(1.0, 1.0, 1.0) + t2 * Color(0.5, 0.7, 1.0);
        }
    } catch (const RaytracerException& e) {
        std::cerr << "Raytracer Exception: " << e.getName() << " - " << e.getType() << std::endl;
        return Color(0, 0, 0);
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