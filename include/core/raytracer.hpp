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

#include "raytracerException.hpp"
#include "check_and_parse.hpp"



class Raytracer {
    public:
        Raytracer(char *file);
        ~Raytracer();

        void run();
    private:
        char *file;
};


#endif /* !RAYTRACEUR_HPP_ */
