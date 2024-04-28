/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Point
*/

#ifndef POINT_HPP_
#define POINT_HPP_

class Point {
public:
    float x, y, z;

    Point(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) : x(_x), y(_y), z(_z) {}
};
#endif /* !POINT_HPP_ */
