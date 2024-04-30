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
    Point originPoint;
    Vector dir;

    Vector direction() const { return dir; }

    Ray(const Point& _origin = Point(), const Vector& _direction = Vector());
    Point at(double t) const;
    Point origin() const;
};

#endif /* RAY_HPP_ */
