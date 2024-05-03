/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

#include "../Interfaces/IPrimitive.hpp"
#include "../Utilities/Point.hpp"
#include "../Utilities/Ray.hpp"
#include "../Utilities/Intersection.hpp"
#include <memory>


class Cylinder : public Primitive {
public:
    Cylinder(const Point &base_center, const Vector &axis_direction, double radius, double height, const Color &color);
    bool intersect(const Ray& ray, Intersection& intersection) const override;

private:
    Point base_center_;
    Vector axis_direction_;
    double radius_;
    double height_;
    Color color_;
};

extern "C" std::unique_ptr<Cylinder> create_cylinder(const Point& base_center, const Vector& axis_direction, double radius, double height, const Color& color);

#endif /* !CYLINDER_HPP_ */
