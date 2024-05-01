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
    double t;
    Point position;
    Vector normal;
    Color color;

    Intersection(double t_val, const Point& pos, const Vector& norm, const Color& col)
        : t(t_val), position(pos), normal(norm), color(col) {}
};

#endif /* !INTERSECTION_HPP_ */
