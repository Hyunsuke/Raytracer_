/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Observer.hpp
*/

#ifndef OBSERVER_HPP_
    #define OBSERVER_HPP_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "../raytracer.hpp"

class Observer {
    public:
        Observer(sf::RenderWindow& window, sf::VertexArray& vertices, Point& Camera) : _window(window), _vertices(vertices), _camera(Camera) {}
        bool WindowLoop();

        void moveCameraRight(double amount);
        void moveCameraLeft(double amount);
        void moveCameraUp(double amount);
        void moveCameraDown(double amount);
        void moveCameraForward(double amount);
        void moveCameraBackward(double amount);
    private:
        sf::RenderWindow& _window;
        sf::VertexArray& _vertices;
        Point& _camera;
        sf::Event _event;
};

#endif /* !OBSERVER_HPP_ */
