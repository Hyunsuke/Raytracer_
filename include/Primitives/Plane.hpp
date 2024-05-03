/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Plane
*/

#ifndef PLANE_HPP_
#define PLANE_HPP_

#include "../Interfaces/IPrimitive.hpp"
#include "../Utilities/Point.hpp"
#include "../Utilities/Ray.hpp"
#include "../Utilities/Intersection.hpp"
#include <memory>

class Plane : public Primitive<Plane> {
    public:
        Plane(const char axis, double position, const Color& color);
        bool intersect(const Ray& ray, Intersection& intersection) const override;

    private:
        char axis_;
        double position_;
        Color color_;
};
extern "C" std::unique_ptr<Primitive<Plane>> create_plane(const char axis, double position, const Color& color);

#endif /* !PLANE_HPP_ */
