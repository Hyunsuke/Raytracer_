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
#include "../Primitives/Cone.hpp"
#include "../core/PrimitiveManager.hpp"


class Raytracer {
    public:
        Raytracer(std::string file, check_and_parse &check_parse);
        ~Raytracer();

        void run();
    private:
        std::string file;
        check_and_parse _parse;
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

        PrimitiveManager<Sphere> sphereManager;
        PrimitiveManager<Cylinder> cylinderManager;
        PrimitiveManager<Plane> planeManager;
        PrimitiveManager<Cone> coneManager;

        //// libsphere /////
        void load_sphere_library(const std::string& libraryPath);
        LibraryLoader<std::unique_ptr<Sphere> (*)(const Point&, double, const Color&)> sphereLibraryLoader;
        std::shared_ptr<Sphere> create_sphere_instance(const Point& center, double radius, const Color& color);

        //// libcylinder /////
        void load_cylinder_library(const std::string& libraryPath);
        LibraryLoader<std::shared_ptr<Cylinder> (*)(const Point&, const Vector&, double, double, const Color&)> cylinderLibraryLoader;
        std::shared_ptr<Cylinder> create_cylinder_instance(const Point& center, const Vector& axis_direction, double radius, double height, const Color& color);

        //// libplane /////
        void load_plane_library(const std::string& libraryPath);
        LibraryLoader<std::shared_ptr<Plane> (*)(const char, double, const Color&)> planeLibraryLoader;
        std::shared_ptr<Plane> create_plane_instance(const char axis, double position, const Color& color);

        //// libcone /////
        void load_cone_library(const std::string& libraryPath);
        LibraryLoader<std::shared_ptr<Cone> (*)(const Point&, const Vector&, double, double, const Color&)> coneLibraryLoader;
        std::shared_ptr<Cone> create_cone_instance(const Point& apex, const Vector& axis_direction, double angle, double height, const Color& color);

};


#endif /* !RAYTRACEUR_HPP_ */
