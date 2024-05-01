/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "../Interfaces/IPrimitive.hpp"
#include "../Utilities/Point.hpp"
#include "../Utilities/Ray.hpp"
#include "../Utilities/Intersection.hpp"
#include <memory>

class Sphere : public Primitive<Sphere> {
public:
    Sphere(const Point& center, double radius);
    bool intersect(const Ray& ray, Intersection& intersection) const override;

private:
    Point center_;
    double radius_;
};

extern "C" std::unique_ptr<Primitive<Sphere>> create_sphere(const Point& center, double radius);

#endif /* !SPHERE_HPP_ */
