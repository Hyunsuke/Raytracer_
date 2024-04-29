/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Point
*/

#ifndef POINT_HPP_
#define POINT_HPP_

#include "Vector.hpp"

class Vector;

class Point {
public:
    float x, y, z;

    Point(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f);

    friend Point operator+(const Point& p, const Vector& v);
    Vector operator-(const Point& other) const;
};

#endif /* POINT_HPP_ */
