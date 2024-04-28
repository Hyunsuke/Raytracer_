/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "../Interfaces/IPrimitive.hpp"

class Sphere : public Primitive {
public:
    Sphere(/* paramètres de construction */);
    bool intersect(const Ray& ray, Intersection& intersection) const override;
};

#endif /* !SPHERE_HPP_ */
