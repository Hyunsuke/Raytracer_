/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Vector
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <cmath>
#include "Point.hpp"

class Vector {
public:
    float x, y, z;

    Vector(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f);

    float length() const;
    float length_squared() const;
    void normalize();

    friend Vector operator-(const Vector& v, const Point& p);
    friend Vector operator-(const Point& p, const Vector& v);
    friend Vector operator-(const Point& p1, const Point& p2);
};

Vector operator+(const Vector& u, const Vector& v);
Vector operator-(const Vector& u, const Vector& v);
Vector operator*(const Vector& u, const Vector& v);
Vector operator*(float t, const Vector& v);
Vector operator*(const Vector& v, float t);
Vector operator/(const Vector& v, float t);
float dot(const Vector& u, const Vector& v);
Vector cross(const Vector& u, const Vector& v);
Vector unit_vector(const Vector& v);



#endif /* !VECTOR_HPP_ */
