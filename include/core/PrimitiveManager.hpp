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
#include <algorithm>

template<typename T>
class PrimitiveManager {
public:
    PrimitiveManager() {}
    ~PrimitiveManager() {
        for (size_t i = 0; i < primitives_.size(); ++i)
            if (primitives_[i])
                primitives_[i].release();

    }

    void clear() {
        primitives_.clear();
    }

    void addPrimitive(std::unique_ptr<Primitive>&& primitive) {
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
    std::vector<std::unique_ptr<Primitive>> primitives_;
};



template<typename... Managers>
bool findClosestIntersectionAmong(const Ray& ray, Intersection& intersection, const Managers&... managers) {
    bool hit = false;
    Intersection closest_intersection;

    auto checkIntersection = [&](const auto& manager) {
        Intersection temp_intersection;
        bool current_hit = manager.findClosestIntersection(ray, temp_intersection);

        if (current_hit && (!hit || temp_intersection.getT() < closest_intersection.getT())) {
            closest_intersection = temp_intersection;
            hit = true;
        }
    };

    (checkIntersection(managers), ...);

    if (hit) {
        intersection = closest_intersection;
        return true;
    } else {
        return false;
    }
}

#endif /* !PRIMITIVEMANAGER_HPP_ */
