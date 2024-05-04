/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "../../../include/Primitives/Sphere.hpp"

Sphere::Sphere(const Point& center, double radius, const Color& color)
    : center_(center), radius_(radius), color_(color) {}

bool Sphere::intersect(const Ray& ray, Intersection& intersection) const {
    Vector oc = center_ - ray.origin();
    double a = dot(ray.direction(), ray.direction());
    double b = dot(oc, ray.direction());
    double c = dot(oc, oc) - radius_ * radius_;
    double discriminant = b * b - a * c;
    if (discriminant > 0) {
        double temp = (-b - sqrt(discriminant)) / a;
        if (temp < intersection.getT()) {
            intersection.setT(temp);
            intersection.setPosition(ray.at(intersection.getT()));
            intersection.setNormal((intersection.getPosition() - center_) / radius_);
            intersection.setColor(color_);
            return true;
        }
    }
    return false;
}

std::unique_ptr<Sphere> create_sphere(const Point& center, double radius, const Color& color)
{
    return std::make_unique<Sphere>(center, radius, color);
}
