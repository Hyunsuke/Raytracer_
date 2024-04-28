/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Vector
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <cmath>

class Vector {
public:
    float x, y, z;

    Vector(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) : x(_x), y(_y), z(_z) {}

    float norm() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    void normalize() {
        float n = norm();
        x /= n;
        y /= n;
        z /= n;
    }
};
#endif /* !VECTOR_HPP_ */
