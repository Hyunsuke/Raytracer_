/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** ILight
*/

#ifndef ILIGHT_HPP_
#define ILIGHT_HPP_

#include "../Utilities/Color.hpp"
#include "../Utilities/Point.hpp"

class Light {
public:
    virtual ~Light() {}
    virtual Color intensityAt(const Point& point) const = 0;
};

#endif /* !ILIGHT_HPP_ */
