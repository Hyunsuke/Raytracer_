/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Intersection
*/

#ifndef INTERSECTION_HPP_
#define INTERSECTION_HPP_

#include "Point.hpp"
#include "Vector.hpp"
#include "Color.hpp"

struct Intersection {
    Point position;
    Vector normal;
    Color color;

    Intersection(const Point& pos, const Vector& norm, const Color& col)
        : position(pos), normal(norm), color(col) {}
};


#endif /* !INTERSECTION_HPP_ */
