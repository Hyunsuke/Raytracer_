/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Point.cpp
*/

#include "raytracer.hpp"

Point::Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

Point operator+(const Point& p, const Vector& v) {
    return Point(p.x + v.x, p.y + v.y, p.z + v.z);
}