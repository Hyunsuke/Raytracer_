/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector.cpp
*/

#include "../../include/Utilities/Vector.hpp"
#include "../../include/Utilities/Point.hpp"

Vector::Vector(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

float Vector::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

float Vector::length_squared() const {
    return x * x + y * y + z * z;
}

void Vector::normalize() {
    float len = length();
    x /= len;
    y /= len;
    z /= len;
}

Vector operator+(const Vector& u, const Vector& v) {
    return Vector(u.x + v.x, u.y + v.y, u.z + v.z);
}

Vector operator-(const Vector& u, const Vector& v) {
    return Vector(u.x - v.x, u.y - v.y, u.z - v.z);
}

Vector operator*(const Vector& u, const Vector& v) {
    return Vector(u.x * v.x, u.y * v.y, u.z * v.z);
}

Vector operator*(float t, const Vector& v) {
    return Vector(t * v.x, t * v.y, t * v.z);
}

Vector operator*(const Vector& v, float t) {
    return t * v;
}

Vector operator/(const Vector& v, float t) {
    return (1 / t) * v;
}

float dot(const Vector& u, const Vector& v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

Vector cross(const Vector& u, const Vector& v) {
    return Vector(u.y * v.z - u.z * v.y,
                  u.z * v.x - u.x * v.z,
                  u.x * v.y - u.y * v.x);
}

Vector unit_vector(const Vector& v) {
    return v / v.length();
}

Vector operator-(const Point& p, const Vector& v) {
    return Vector(p.x - v.x, p.y - v.y, p.z - v.z);
}

Vector operator-(const Vector& v, const Point& p) {
    return Vector(v.x - p.x, v.y - p.y, v.z - p.z);
}
