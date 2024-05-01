/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "../../../include/Primitives/Sphere.hpp"

Sphere::Sphere(const Point& center, double radius)
    : center_(center), radius_(radius) {}

bool Sphere::intersect(const Ray& ray, Intersection& intersection) const {
    Vector oc = center_ - ray.origin();
    double a = dot(ray.direction(), ray.direction());
    double b = dot(oc, ray.direction());
    double c = dot(oc, oc) - radius_ * radius_;
    double discriminant = b * b - a * c;
    if (discriminant > 0) {
        double temp = (-b - sqrt(discriminant)) / a;
        if (temp < intersection.t) {
            intersection.t = temp;
            intersection.position = ray.at(intersection.t);
            intersection.normal = (intersection.position - center_) / radius_;
            intersection.color = Color(0.5, 0.5, 0.5);
            return true;
        }
    }
    return false;
}

std::unique_ptr<Primitive<Sphere>> create_sphere(const Point& center, double radius) {
    return std::make_unique<Sphere>(center, radius);
}