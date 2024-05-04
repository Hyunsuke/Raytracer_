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


class Cone : public Primitive {
    public:
        Cone() = default; // Parser constructor
        Cone(const Point& apex, const Vector& axis_direction, double angle, double height, const Color& color);
        bool intersect(const Ray& ray, Intersection& intersection) const override;
        void setPosX(int x) { _pos_x = x; };
        void setPosY(int y) { _pos_y = y; };
        void setPosZ(int z) { _pos_z = z; };
        void setAxisX(int x) { _axis_x = x; };
        void setAxisY(int y) { _axis_y = y; };
        void setAxisZ(int z) { _axis_z = z; };
        void setAngle(double angle) { _angle = angle; };
        void setHeight(double height) { _height = height; };
        void setColorR(int cR) { _color_r = cR; };
        void setColorG(int cG) { _color_g = cG; };
        void setColorB(int cB) { _color_b = cB; };

        int getPosX() { return _pos_x; }
        int getPosY() { return _pos_y; }
        int getPosZ() { return _pos_z; }
        int getAxisX() { return _axis_x; }
        int getAxisY() { return _axis_y; }
        int getAxisZ() { return _axis_z; }
        double getAngle() { return _angle; }
        double getHeight() { return _height; }
        int getcR() { return _color_r; }
        int getcG() { return _color_g; }
        int getcB() { return _color_b; }

    private:
        int _pos_x = 0;
        int _pos_y = 0;
        int _pos_z = 0;
        int _axis_x = 0;
        int _axis_y = 0;
        int _axis_z = 0;
        double _angle;
        double _height;
        int _color_r;
        int _color_g;
        int _color_b;
    // 16 Private
        Point apex_;
        Vector axis_direction_;
        double angle_;
        double height_;
        Color color_;
};

extern "C" std::unique_ptr<Cone> create_cone(const Point& apex, const Vector& axis_direction, double angle, double height, const Color& color);

#endif /* !CONE_HPP_ */
