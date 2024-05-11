/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "../../../include/Primitives/Plane.hpp"

Plane::Plane(const char axis, double position, const Color& color)
        : axis_(axis), position_(position), color_(color)
{}

void Plane::rotate(double angle, const Vector& axis)
{
    (void)angle;
    (void)axis;
}

bool Plane::intersect(const Ray& ray, Intersection& intersection)
{
    Vector normal;
    double plane_coord;
    if (axis_ == 'X') {
        normal = Vector(1, 0, 0);
        plane_coord = position_;
    } else if (axis_ == 'Y') {
        normal = Vector(0, 1, 0);
        plane_coord = position_;
    } else { // axis_ == 'Z'
        normal = Vector(0, 0, 1);
        plane_coord = position_;
    }

    double denom = dot(normal, ray.direction());

    // Rayon parallèle au plan
    if (fabs(denom) < 0.00001) {
        return false;
    }

    // double t = (plane_coord - ray.origin().coord(axis_ - 'X')) / denom;
    double t = (plane_coord - (axis_ == 'X' ? ray.origin().x :
                               axis_ == 'Y' ? ray.origin().y :
                               ray.origin().z)) / denom;

    // Intersection derrière le rayon
    if (t < 0) {
        return false;
    }

    Point intersection_point = ray.at(t);
    Vector p_to_intersection = intersection_point - Point(axis_ == 'X' ? plane_coord : 0.0,
                                                          axis_ == 'Y' ? plane_coord : 0.0,
                                                          axis_ == 'Z' ? plane_coord : 0.0);

    // Vérifier si le point d'intersection est sur le plan
    double epsilon = 0.00001;

    if (fabs(dot(p_to_intersection, normal)) < epsilon) {
        intersection.setT(t);
        intersection.setPosition(intersection_point);
        intersection.setNormal(normal);
        intersection.setColor(color_);
        return true;
    }
    return false;
}


std::unique_ptr<Plane> create_plane(const char axis, double position, const Color& color)
{
    return std::make_unique<Plane>(axis, position, color);
}