/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** sfml.cpp
*/

#include "raytracer.hpp"
#include <thread>
#include <vector>

void Raytracer::renderSection(int startRow, int endRow, Vector pixel00_loc, Vector pixel_delta_u, Vector pixel_delta_v)
{
    for (int j = startRow; j < endRow; j++) {
        for (int i = 0; i < image_width; i++) {
            Vector pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            Vector ray_direction = pixel_center - Camera;
            Ray r(Camera, ray_direction);

            Color pixel_color = ray_color(r);
            image[j][i] = pixel_color;
        }
    }
}

void Raytracer::create_map_multithreaded(Vector pixel00_loc, Vector pixel_delta_u, Vector pixel_delta_v)
{
    const int numThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    int rowsPerThread = image_height / numThreads;
    int extraRows = image_height % numThreads;

    int startRow = 0;
    int endRow = rowsPerThread;

    for (int i = 0; i < numThreads; ++i) {
        if (i == numThreads - 1)
            endRow += extraRows;
        threads.emplace_back(&Raytracer::renderSection, this, startRow, endRow, pixel00_loc, pixel_delta_u, pixel_delta_v);
        startRow = endRow;
        endRow += rowsPerThread;
    }

    for (auto& t : threads) {
        t.join();
    }
}

sf::VertexArray Raytracer::conver_map()
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
    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (double(image_width)/image_height);
    Vector viewport_u = Vector(viewport_width, 0, 0);
    Vector viewport_v = Vector(0, -viewport_height, 0);
    Vector pixel_delta_u = viewport_u / image_width;
    Vector pixel_delta_v = viewport_v / image_height;
    Vector viewport_upper_left = Camera - Vector(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    Vector pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    create_map_multithreaded(pixel00_loc, pixel_delta_u, pixel_delta_v); // Utiliser la version multithreaded

    return conver_map();
}

// void Raytracer::WindowLoop()
// {
//     while (this->_window.pollEvent(this->_event)) {
//         if (this->_event.type == sf::Event::Closed)
//             this->_window.close();
//     }
//     Point PastCam = Camera;
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//         Camera.Set_X(Camera.Get_X() + 0.1);
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//         Camera.Set_X(Camera.Get_X() - 0.1);
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//         Camera.Set_Y(Camera.Get_Y() + 0.1);
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//         Camera.Set_Y(Camera.Get_Y() - 0.1);
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
//         Camera.Set_Z(Camera.Get_Z() - 0.1);
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//         Camera.Set_Z(Camera.Get_Z() + 0.1);
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
//         this->_window.close();
//     this->_window.clear();
//     if (PastCam != Camera)
//         vertices = create_map();
//     this->_window.draw(vertices);
//     this->_window.display();
// }