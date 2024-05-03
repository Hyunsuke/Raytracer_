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
#include <dlfcn.h>
#include <memory>

#include "raytracerException.hpp"
#include "check_and_parse.hpp"
#include "../Utilities/Color.hpp"
#include "../Utilities/Ray.hpp"
#include "../Utilities/Point.hpp"
#include "../Primitives/Sphere.hpp"
#include "../Interfaces/IPrimitive.hpp"
#include "../core/libloader.hpp"
#include "../Primitives/Cylinder.hpp"
#include "../Primitives/Plane.hpp"


class Raytracer {
    public:
        Raytracer(std::string file);
        ~Raytracer() = default;

        void run();
    private:
        std::string file;
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


        //// libsphere /////
        void load_sphere_library(const std::string& libraryPath);
        LibraryLoader<std::unique_ptr<Primitive<Sphere>> (*)(const Point&, double, const Color&)> sphereLibraryLoader;
        std::unique_ptr<Primitive<Sphere>> create_sphere_instance(const Point& center, double radius, const Color& color);

        //// libcylinder /////
        void load_cylinder_library(const std::string& libraryPath);
        LibraryLoader<std::unique_ptr<Primitive<Cylinder>> (*)(const Point&, const Vector&, double, double, const Color&)> cylinderLibraryLoader;
        std::unique_ptr<Primitive<Cylinder>> create_cylinder_instance(const Point& center, const Vector& axis_direction, double radius, double height, const Color& color);

        //// libplane /////
        void load_plane_library(const std::string& libraryPath);
        LibraryLoader<std::unique_ptr<Primitive<Plane>> (*)(const char, double, const Color&)> planeLibraryLoader;
        std::unique_ptr<Primitive<Plane>> create_plane_instance(const char axis, double position, const Color& color);

};


#endif /* !RAYTRACEUR_HPP_ */
