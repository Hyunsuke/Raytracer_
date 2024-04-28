/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include "Vector.hpp"

class Color {
    public:
        float r, g, b;

        Color(float red = 0.0f, float green = 0.0f, float blue = 0.0f);
        void clamp();
        void write_color(std::ostream& out, const Color& pixel_color);
};

#endif /* COLOR_HPP_ */

