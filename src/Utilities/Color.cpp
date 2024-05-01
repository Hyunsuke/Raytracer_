/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Color.cpp
*/

#include "../../include/Utilities/Color.hpp"

Color::Color(float red, float green, float blue) : r(red), g(green), b(blue)
{
}

void Color::clamp() {
    r = (r < 0.0f) ? 0.0f : (r > 1.0f) ? 1.0f : r;
    g = (g < 0.0f) ? 0.0f : (g > 1.0f) ? 1.0f : g;
    b = (b < 0.0f) ? 0.0f : (b > 1.0f) ? 1.0f : b;
}

void Color::write_color(std::ostream &out, const Color &pixel_color)
{
    auto r = pixel_color.r;
    auto g = pixel_color.g;
    auto b = pixel_color.b;

    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}