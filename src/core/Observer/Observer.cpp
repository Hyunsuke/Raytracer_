/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Observer.cpp
*/

#include "raytracer.hpp"

bool Observer::WindowLoop()
{
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            this->_window.close();
    }
    Point PastCam = _camera;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        moveCameraRight(0.1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        moveCameraLeft(0.1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        moveCameraUp(0.1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        moveCameraDown(0.1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        moveCameraForward(0.1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        moveCameraBackward(0.1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        this->_window.close();
    this->_window.clear();
    this->_window.draw(_vertices);
    this->_window.display();
    if (PastCam != _camera)
        return true;
    return false;
}



void Observer::moveCameraRight(double amount) {
    _camera.Set_X(_camera.Get_X() + amount);
}

void Observer::moveCameraLeft(double amount) {
    _camera.Set_X(_camera.Get_X() - amount);
}

void Observer::moveCameraUp(double amount) {
    _camera.Set_Y(_camera.Get_Y() + amount);
}

void Observer::moveCameraDown(double amount) {
    _camera.Set_Y(_camera.Get_Y() - amount);
}

void Observer::moveCameraForward(double amount) {
    _camera.Set_Z(_camera.Get_Z() - amount);
}

void Observer::moveCameraBackward(double amount) {
    _camera.Set_Z(_camera.Get_Z() + amount);
}
