/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "../../../include/Primitives/Cylinder.hpp"

Cylinder::Cylinder(const Point& base_center, const Vector &axis_direction, double radius, double height, const Color &color)
        : base_center_(base_center), axis_direction_(axis_direction), radius_(radius), height_(height), color_(color) {}

double length(const Vector& vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}


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
            Vector normal;
            if (intersect_y < 0.0001 || height_ - intersect_y < 0.0001) {
                normal = axis_direction_;
            } else {
                normal = unit_vector(intersection.getPosition() - (base_center_ + intersect_y * axis_direction_));
            }
            intersection.setNormal(normal);
            intersection.setColor(color_);
            return true;
        }
    }
    double t_cap = (height_ - dot(ray.origin() - base_center_, axis_direction_)) / dot(ray.direction(), axis_direction_);
    if (t_cap > 0) {
        Point cap_intersection = ray.at(t_cap);
        double dist_to_axis = (cap_intersection - (base_center_ + height_ * axis_direction_)).length();
        if (dist_to_axis <= radius_) {
            intersection.setT(t_cap);
            intersection.setPosition(cap_intersection);
            intersection.setNormal(unit_vector(cap_intersection - (base_center_ + height_ * axis_direction_)));
            intersection.setColor(color_);
            return true;
        }
    }
    t_cap = -dot(ray.origin() - base_center_, axis_direction_) / dot(ray.direction(), axis_direction_);
    if (t_cap > 0) {
        Point cap_intersection = ray.at(t_cap);
        double dist_to_axis = (cap_intersection - base_center_).length();
        if (dist_to_axis <= radius_) {
            intersection.setT(t_cap);
            intersection.setPosition(cap_intersection);
            intersection.setNormal(-1.0 * unit_vector(cap_intersection - base_center_));
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