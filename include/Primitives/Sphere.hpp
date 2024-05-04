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

class Sphere : public Primitive {
    public:
        Sphere() = default; // Parser constructor
        ~Sphere() {}; // Destructor
        Sphere(const Point& center, double radius, const Color& color);
        bool intersect(const Ray& ray, Intersection& intersection) const override;
        void setX(int x) { _x = x; };
        void setY(int y) { _y = y; };
        void setZ(int z) { _z = z; };
        void setR(double r) { _r = r; };
        void setColorR(int cR) { _color_r = cR; };
        void setColorG(int cG) { _color_g = cG; };
        void setColorB(int cB) { _color_b = cB; };
        int getX() { return _x; }
        int getY() { return _y; }
        int getZ() { return _z; }
        double getR() { return _r; }
        int getcR() { return _color_r; }
        int getcG() { return _color_g; }
        int getcB() { return _color_b; }

    private:
        int _x = 0;
        int _y = 0;
        int _z = 0;
        double _r = 0;
        int _color_r = 0;
        int _color_g = 0;
        int _color_b = 0;
    // 16 private
        Point center_;
        double radius_;
        Color color_;
};

extern "C" std::unique_ptr<Sphere> create_sphere(const Point& center, double radius, const Color& color);

#endif /* !SPHERE_HPP_ */
