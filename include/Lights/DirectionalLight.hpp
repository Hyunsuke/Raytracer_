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
    DirectionalLight(/* paramètres de construction */);
    Color intensityAt(const Point& point) const override;
};

#endif /* !DIRECTIONALLIGHT_HPP_ */
