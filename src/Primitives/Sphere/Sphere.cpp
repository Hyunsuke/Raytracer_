/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "../../../include/Primitives/Sphere.hpp"

Sphere::Sphere(const Point& center, double radius, const Color& color)
    : center_(center), radius_(radius), color_(color)
{}

void Sphere::rotate(double angle, const Vector& axis)
{
    (void)angle;
    (void)axis;
}

bool Sphere::intersect(const Ray& ray, Intersection& intersection)
{
    Vector oc = ray.origin() - center_;
    double a = dot(ray.direction(), ray.direction());
    double b = 2.0 * dot(oc, ray.direction());
    double c = dot(oc, oc) - radius_ * radius_;
    double discriminant = b * b - 4 * a * c;
    const double EPSILON = 1e-6;

    if (discriminant > 0) {
        double t = (-b - sqrt(discriminant)) / (2.0 * a);
        if (t > EPSILON) {
            intersection.setT(t);
            intersection.setPosition(ray.at(t));
            intersection.setNormal((intersection.getPosition() - center_) / radius_);
            intersection.setColor(color_);
            return true;
        }
        t = (-b + sqrt(discriminant)) / (2.0 * a);
        if (t > EPSILON) {
            intersection.setT(t);
            intersection.setPosition(ray.at(t));
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
