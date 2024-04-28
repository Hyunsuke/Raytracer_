/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

struct Color {
    float r, g, b;

    Color(float red = 0.0f, float green = 0.0f, float blue = 0.0f)
        : r(red), g(green), b(blue) {}

    void clamp() {
        r = (r < 0.0f) ? 0.0f : (r > 1.0f) ? 1.0f : r;
        g = (g < 0.0f) ? 0.0f : (g > 1.0f) ? 1.0f : g;
        b = (b < 0.0f) ? 0.0f : (b > 1.0f) ? 1.0f : b;
    }
};

#endif /* !COLOR_HPP_ */
