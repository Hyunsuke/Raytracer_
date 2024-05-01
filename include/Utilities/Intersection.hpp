/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Intersection
*/

#ifndef INTERSECTION_HPP_
#define INTERSECTION_HPP_

#include "Point.hpp"
#include "Vector.hpp"
#include "Color.hpp"

class Intersection {
private:
    double t;
    Point position;
    Vector normal;
    Color color;

public:
    Intersection(double t_val = 0.0, const Point& pos = Point(), const Vector& norm = Vector(), const Color& col = Color())
        : t(t_val), position(pos), normal(norm), color(col) {}

    double getT() const { return t; }
    const Point& getPosition() const { return position; }
    const Vector& getNormal() const { return normal; }
    const Color& getColor() const { return color; }

    void setT(double t_val) { t = t_val; }
    void setPosition(const Point& pos) { position = pos; }
    void setNormal(const Vector& norm) { normal = norm; }
    void setColor(const Color& col) { color = col; }
};

#endif /* !INTERSECTION_HPP_ */
