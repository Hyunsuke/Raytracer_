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

Color ray_color(const Ray& r) {
    Vector unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y + 1.0);
    return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

sf::VertexArray create_map(int image_width, int image_height, std::vector<std::vector<Color>> &image)
{
    sf::VertexArray vertices(sf::Points, image_width * image_height);
    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            int index = i + j * image_width;
            vertices[index].position = sf::Vector2f(i, j);
            vertices[index].color = sf::Color(
                static_cast<sf::Uint8>(image[j][i].r * 255),
                static_cast<sf::Uint8>(image[j][i].g * 255),
                static_cast<sf::Uint8>(image[j][i].b * 255)
            );
        }
    }
    return vertices;
}

sf::VertexArray create_map(std::vector<std::vector<Color>> &image, int x, int y, int z)
{
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height);
    auto camera_center = Point(x, y, z);
    auto viewport_u = Vector(viewport_width, 0, 0);
    auto viewport_v = Vector(0, -viewport_height, 0);
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;
    auto viewport_upper_left = camera_center - Vector(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            Ray r(camera_center, ray_direction);

            Color pixel_color = ray_color(r);
            image[j][i] = pixel_color;

        }
    }
    sf::VertexArray vertices = create_map(image_width, image_height, image);
    return vertices;
}

void Raytracer::run()
{
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;
    int image_height = int(image_width / aspect_ratio);
    int x = 0, y = 0, z = 0;
    std::vector<std::vector<Color>> image(image_height, std::vector<Color>(image_width));
    sf::VertexArray vertices = create_map(image, 0, 0, 0);
    sf::RenderWindow window(sf::VideoMode(image_width, image_height), "raytracer");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            x++;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            x--;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            y++;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            y--;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            z++;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            z--;
        window.clear();
        window.draw(create_map(image, x, y, z));
        window.display();
    }
}