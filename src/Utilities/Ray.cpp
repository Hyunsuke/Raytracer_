/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Ray.cpp
*/

#include "raytracer.hpp"

Ray::Ray(const Point& _origin, const Vector& _direction) : origin(_origin), dir(_direction) {}

Point Ray::at(double t) const {
    return origin + t * dir;
}

