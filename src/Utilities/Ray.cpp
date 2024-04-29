/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Ray.cpp
*/

#include "raytracer.hpp"

Ray::Ray(const Point& _origin, const Vector& _direction) : originPoint(_origin), dir(_direction) {}

Point Ray::at(double t) const {
    return originPoint + t * dir;
}

Point Ray::origin() const {
    return this->originPoint;
}
