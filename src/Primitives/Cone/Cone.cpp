/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "../../../include/Primitives/Cone.hpp"

Cone::Cone(const Point& apex, const Vector& axis_direction, double angle, double height, const Color& color)
        : apex_(apex), axis_direction_(axis_direction), angle_(angle), height_(height), color_(color)
{}


bool Cone::intersect(const Ray& ray, Intersection& intersection) const {
    Vector oc = ray.origin() - apex_;
    double cos_angle = cos(angle_);
    double a = dot(ray.direction() - axis_direction_ * dot(ray.direction(), axis_direction_), ray.direction() - axis_direction_ * dot(ray.direction(), axis_direction_)) - cos_angle * cos_angle * dot(ray.direction(), ray.direction());
    double b = 2.0 * (dot(ray.direction() - axis_direction_ * dot(ray.direction(), axis_direction_), oc - axis_direction_ * dot(oc, axis_direction_)) - cos_angle * cos_angle * dot(ray.direction(), oc));
    double c = dot(oc - axis_direction_ * dot(oc, axis_direction_), oc - axis_direction_ * dot(oc, axis_direction_)) - cos_angle * cos_angle * dot(oc, oc);
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double temp = (-b - sqrt(discriminant)) / (2.0 * a);
        double intersect_y = dot(ray.at(temp) - apex_, axis_direction_);
        if (temp > 0 && intersect_y > 0 && intersect_y < height_) {
            intersection.setT(temp);
            intersection.setPosition(ray.at(temp));
            Vector normal = unit_vector(intersection.getPosition() - (apex_ + intersect_y * axis_direction_));
            intersection.setNormal(normal);
            intersection.setColor(color_);
            return true;
        }
    }
    double t_base = -dot(ray.origin() - apex_, axis_direction_) / dot(ray.direction(), axis_direction_);
    if (t_base > 0) {
        Point base_intersection = ray.at(t_base);
        if ((base_intersection - apex_).length_squared() <= tan(angle_) * tan(angle_) * (base_intersection - apex_).length_squared()) {
            intersection.setT(t_base);
            intersection.setPosition(base_intersection);
            intersection.setNormal(1.0 * axis_direction_);
            intersection.setColor(color_);
            return true;
        }
    }
    return false;
}





extern "C" std::unique_ptr<Cone> create_cone(const Point& apex, const Vector& axis_direction, double angle, double height, const Color& color)
{
    return std::make_unique<Cone>(apex, -1 * axis_direction, angle, height, color);
}