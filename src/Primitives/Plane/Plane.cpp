/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "../../../include/Primitives/Plane.hpp"

Plane::Plane(const char axis, double position, const Color& color)
        : axis_(axis), position_(position), color_(color)
{
}
bool Plane::intersect(const Ray& ray, Intersection& intersection) const {
        double t;
        if (axis_ == 'X') {
            t = (position_ - ray.origin().x) / ray.direction().x;
        } else if (axis_ == 'Y') {
            t = (position_ - ray.origin().y) / ray.direction().y;
        } else { // axis_ == 'Z'
            t = (position_ - ray.origin().z) / ray.direction().z;
        }

        if (t > 0) {
            Point intersection_point = ray.at(t);
            double epsilon = 0.0001;
            if (axis_ == 'X' && fabs(intersection_point.x - position_) < epsilon) {
                intersection.setT(t);
                intersection.setPosition(intersection_point);
                intersection.setNormal(Vector(-1, 0, 0));
                intersection.setColor(color_);
                return true;
            } else if (axis_ == 'Y' && fabs(intersection_point.y - position_) < epsilon) {
                intersection.setT(t);
                intersection.setPosition(intersection_point);
                intersection.setNormal(Vector(0, -1, 0));
                intersection.setColor(color_);
                return true;
            } else if (axis_ == 'Z' && fabs(intersection_point.z - position_) < epsilon) {
                intersection.setT(t);
                intersection.setPosition(intersection_point);
                intersection.setNormal(Vector(0, 0, -1));
                intersection.setColor(color_);
                return true;
            }
        }
        return false;
    }


std::unique_ptr<Primitive<Plane>> create_plane(const char axis, double position, const Color& color)
{
    return std::make_unique<Plane>(axis, position, color);
}