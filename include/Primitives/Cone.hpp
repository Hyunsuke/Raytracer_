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
        Cone(const Point& apex, const Vector& axis_direction, double angle, double height, const Color& color, const Vector& rotation_axis, double rotation_angle_deg);
        bool intersect(const Ray& ray, Intersection& intersection) override;
        void rotate(double angle, const Vector& axis) override;

        void setX(int x) override { _pos_x = x; };
        void setY(int y) override { _pos_y = y; };
        void setZ(int z) override { _pos_z = z; };
        void setColorR(int cR) override { _color_r = cR; };
        void setColorG(int cG) override { _color_g = cG; };
        void setColorB(int cB) override { _color_b = cB; };

        int getX() override { return _pos_x; }
        int getY() override { return _pos_y; }
        int getZ() override { return _pos_z; }
        int getcR() override { return _color_r; }
        int getcG() override { return _color_g; }
        int getcB() override { return _color_b; }

        void setAxisX(int x) { _axis_x = x; };
        void setAxisY(int y) { _axis_y = y; };
        void setAxisZ(int z) { _axis_z = z; };
        void setAngle(double angle) { _angle = angle; };
        void setHeight(double height) { _height = height; };

        int getAxisX() { return _axis_x; }
        int getAxisY() { return _axis_y; }
        int getAxisZ() { return _axis_z; }
        double getAngle() { return _angle; }
        double getHeight() { return _height; }


        void setRotationAxis(std::string axis) { _rotation_axis = axis; }
        std::string getRotationAxis() { return _rotation_axis; }
        void setRotationDegree(double rD) { _rotation_degree = rD; };
        double getRotationDegree() { return _rotation_degree; }

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
        double _rotation_degree = 0;
        std::string _rotation_axis;
    // 16 Private
        Point apex_;
        Vector axis_direction_;
        double angle_;
        double height_;
        Color color_;
};

extern "C" std::unique_ptr<Cone> create_cone(const Point& apex, const Vector& axis_direction, double angle, double height, const Color& color, const Vector& rotation_axis, double rotation_angle_deg);

#endif /* !CONE_HPP_ */
