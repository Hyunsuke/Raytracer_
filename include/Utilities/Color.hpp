/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <iostream>
#include "Vector.hpp"

class Color {
public:
    float r, g, b;

    Color(float red = 0.0f, float green = 0.0f, float blue = 0.0f);
    void clamp();
    void write_color(std::ostream& out, const Color& pixel_color);

    friend Color operator*(const Color& c, double scalar) {
        return Color(c.r * scalar, c.g * scalar, c.b * scalar);
    }
    
    friend Color operator*(double scalar, const Color& c) {
        return c * scalar;
    }
    
    friend Color operator+(const Color& c1, const Color& c2) {
        return Color(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
    }

    Color& operator+=(const Color& rhs);
    Color& operator/=(double scalar);
    Color operator/(double scalar) const;
};

#endif /* COLOR_HPP_ */

