/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "../../../include/Primitives/Cylinder.hpp"

Cylinder::Cylinder(const Point& base_center, const Vector &axis_direction, double radius, double height, const Color &color)
        : base_center_(base_center), axis_direction_(axis_direction), radius_(radius), height_(height), color_(color) {}

bool Cylinder::intersect(const Ray& ray, Intersection& intersection) const
{
    Vector oc = ray.origin() - base_center_;
    double a = dot(ray.direction() - axis_direction_ * dot(ray.direction(), axis_direction_), ray.direction() - axis_direction_ * dot(ray.direction(), axis_direction_));
    double b = 2.0 * dot(ray.direction() - axis_direction_ * dot(ray.direction(), axis_direction_), oc - axis_direction_ * dot(oc, axis_direction_));
    double c = dot(oc - axis_direction_ * dot(oc, axis_direction_), oc - axis_direction_ * dot(oc, axis_direction_)) - radius_ * radius_;
    double discriminant = b * b - 4 * a * c;
    if (discriminant >= 0) {
        double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
        double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
        double t = (t1 > 0) ? t1 : t2;
        double intersect_y = dot(ray.at(t) - base_center_, axis_direction_);
        if (intersect_y >= 0 && intersect_y <= height_) {
            intersection.setT(t);
            intersection.setPosition(ray.at(t));
            Vector normal = unit_vector(intersection.getPosition() - (base_center_ + intersect_y * axis_direction_));
            intersection.setNormal(normal);
            intersection.setColor(color_);
            return true;
        }
    }
    return false;
}

std::unique_ptr<Cylinder> create_cylinder(const Point& base_center, const Vector& axis_direction, double radius, double height, const Color& color)
{
    return std::make_unique<Cylinder>(base_center, axis_direction, radius, height, color);
}