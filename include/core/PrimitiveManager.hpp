/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** PrimitiveManager
*/

#ifndef PRIMITIVEMANAGER_HPP_
#define PRIMITIVEMANAGER_HPP_

#include "../Interfaces/IPrimitive.hpp"
#include <vector>
#include <memory>

template<typename T>
class PrimitiveManager {
public:
    PrimitiveManager() {}

    ~PrimitiveManager() {}

    void addPrimitive(std::shared_ptr<Primitive>&& primitive) {
        primitives_.push_back(std::move(primitive));
    }

    bool findClosestIntersection(const Ray& ray, Intersection& intersection) const {
        Intersection closest_intersection;
        bool hit = false;

        for (const auto& primitive : primitives_) {
            Intersection temp_intersection;
            if (primitive->intersect(ray, temp_intersection)) {
                if (!hit || temp_intersection.getT() < closest_intersection.getT()) {
                    closest_intersection = temp_intersection;
                    hit = true;
                }
            }
        }

        if (hit) {
            intersection = closest_intersection;
            return true;
        } else {
            return false;
        }
    }

private:
    std::vector<std::shared_ptr<Primitive>> primitives_;
};

#endif /* !PRIMITIVEMANAGER_HPP_ */
