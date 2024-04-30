/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** sfml.cpp
*/

#include "raytracer.hpp"

sf::VertexArray Raytracer::conver_map(int image_width, int image_height, std::vector<std::vector<Color>> &image)
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

sf::VertexArray Raytracer::create_map()
{
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height);
    auto viewport_u = Vector(viewport_width, 0, 0);
    auto viewport_v = Vector(0, -viewport_height, 0);
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;
    auto viewport_upper_left = Camera - Vector(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - Camera;
            Ray r(Camera, ray_direction);

            Color pixel_color = ray_color(r);
            image[j][i] = pixel_color;

        }
    }
    return conver_map(image_width, image_height, image);
}

void Raytracer::WindowLoop()
{
        while (this->_window.pollEvent(this->_event)) {
            if (this->_event.type == sf::Event::Closed) {
                this->_window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            Camera.Set_X(Camera.Get_X() + 0.1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            Camera.Set_X(Camera.Get_X() - 0.1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            Camera.Set_Y(Camera.Get_Y() + 0.1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            Camera.Set_Y(Camera.Get_Y() - 0.1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            Camera.Set_Z(Camera.Get_Z() - 0.1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            Camera.Set_Z(Camera.Get_Z() + 0.1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            this->_window.close();
        this->_window.clear();
        this->_window.draw(create_map());
        this->_window.display();
}