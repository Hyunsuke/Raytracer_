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

        void setX(int x) override { _x = x; };
        void setY(int y) override { _y = y; };
        void setZ(int z) override { _z = z; };
        void setColorR(int cR) override { _color_r = cR; };
        void setColorG(int cG) override { _color_g = cG; };
        void setColorB(int cB) override { _color_b = cB; };

        int getX() override { return _x; }
        int getY() override { return _y; }
        int getZ() override { return _z; }
        int getcR() override { return _color_r; }
        int getcG() override { return _color_g; }
        int getcB() override { return _color_b; }

        void setR(double r) { _r = r; };
        double getR() { return _r; }

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
