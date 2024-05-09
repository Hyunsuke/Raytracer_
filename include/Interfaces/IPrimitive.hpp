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

class Primitive {
    public:
        virtual ~Primitive() {}
        virtual bool intersect(const Ray& ray, Intersection& intersection) const = 0;

        virtual void setX(int x) = 0;
        virtual void setY(int y) = 0;
        virtual void setZ(int z) = 0;
        virtual void setColorR(int cR) = 0;
        virtual void setColorG(int cG) = 0;
        virtual void setColorB(int cB) = 0;

        virtual int getX() = 0;
        virtual int getY() = 0;
        virtual int getZ() = 0;
        virtual int getcR() = 0;
        virtual int getcG() = 0;
        virtual int getcB() = 0;
};

#endif /* !IPRIMITIVE_HPP_ */
