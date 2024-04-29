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

Vector operator-(const Point& p1, const Point& p2) {
    return Vector(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
}

Vector Point::operator-(const Point& other) const {
    return Vector(x - other.x, y - other.y, z - other.z);
}