/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Cone
*/

#ifndef CONE_HPP_
#define CONE_HPP_

#include "../Interfaces/IPrimitive.hpp"
#include "../Utilities/Point.hpp"
#include "../Utilities/Ray.hpp"
#include "../Utilities/Intersection.hpp"
#include <memory>


class Cone : public Primitive<Cone> {
    public:
        Cone(const Point& apex, const Vector& axis_direction, double angle, double height, const Color& color);
        bool intersect(const Ray& ray, Intersection& intersection) const override;

    private:
        Point apex_;
        Vector axis_direction_;
        double angle_;
        double height_;
        Color color_;
};

extern "C" std::unique_ptr<Primitive<Cone>> create_cone(const Point& apex, const Vector& axis_direction, double angle, double height, const Color& color);

#endif /* !CONE_HPP_ */
