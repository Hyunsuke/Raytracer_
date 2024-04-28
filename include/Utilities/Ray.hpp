/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_

#include "Point.hpp"
#include "Vector.hpp"

class Ray {
public:
    Point origin;
    Vector direction;

    Ray(const Point& _origin = Point(), const Vector& _direction = Vector())
        : origin(_origin), direction(_direction) {}
};

#endif /* !RAY_HPP_ */
