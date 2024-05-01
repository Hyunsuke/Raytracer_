/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** raytraceur
*/

#ifndef RAYTRACEUR_HPP_
#define RAYTRACEUR_HPP_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <libconfig.h++>
#include <string>
#include <fstream>

#include "raytracerException.hpp"
#include "check_and_parse.hpp"
#include "../Utilities/Color.hpp"
#include "../Utilities/Ray.hpp"
#include "../Utilities/Point.hpp"


class Raytracer {
    public:
        Raytracer(char *file);
        ~Raytracer();

        void run();
    private:
        char *file;
        sf::RenderWindow _window;
        sf::Event _event;
        Point Camera = Point(0, 0, 0);
        std::vector<std::vector<Color>> image;
        sf::VertexArray vertices;
        int image_width;
        int image_height;

        Color ray_color(const Ray &r);
        sf::VertexArray conver_map();
        sf::VertexArray create_map();
        void WindowLoop();

        void save_ppm();

};


#endif /* !RAYTRACEUR_HPP_ */
