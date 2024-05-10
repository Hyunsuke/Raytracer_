/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** DirectionalLight
*/

#ifndef DIRECTIONALLIGHT_HPP_
#define DIRECTIONALLIGHT_HPP_

#include "../Interfaces/ILight.hpp"

class DirectionalLight : public Light {
public:
    DirectionalLight(/* paramètres de construction */) = default;
    // Color intensityAt(const Point& point) const override { return Color(0, 0, 0); };
    void setX(double x) { _x = x; }
    void setY(double y) { _y = y; }
    void setZ(double z) { _z = z; }
    double getX() { return _x; }
    double getY() { return _y; }
    double getZ() { return _z; }

private:
    double _x = 0;
    double _y = 0;
    double _z = 0;
};

#endif /* !DIRECTIONALLIGHT_HPP_ */
