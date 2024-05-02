/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** IPrimitive
*/

#ifndef IPRIMITIVE_HPP_
#define IPRIMITIVE_HPP_

#include "../Utilities/Ray.hpp"
#include "../Utilities/Intersection.hpp"

template<typename T>
class Primitive {
    public:
        virtual ~Primitive() {}
        virtual bool intersect(const Ray& ray, Intersection& intersection) const = 0;
};

#endif /* !IPRIMITIVE_HPP_ */
