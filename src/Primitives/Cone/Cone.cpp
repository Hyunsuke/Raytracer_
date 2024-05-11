/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "../../../include/Primitives/Cone.hpp"

Cone::Cone(const Point& apex, const Vector& axis_direction, double angle, double height, const Color& color, const Vector& rotation_axis, double rotation_angle_deg)
        : apex_(apex), axis_direction_(axis_direction), angle_(angle), height_(height), color_(color)
{
    rotate(rotation_angle_deg, rotation_axis);
}

void Cone::rotate(double angle, const Vector& axis)
{
    double angle_rad = angle * M_PI / 180.0;
    double cos_angle = cos(angle_rad);
    double sin_angle = sin(angle_rad);

    // Calcul des nouveaux axes du cône
    double u = axis.x;
    double v = axis.y;
    double w = axis.z;

    double x = axis_direction_.x;
    double y = axis_direction_.y;
    double z = axis_direction_.z;

    double new_x = (u * u + (1 - u * u) * cos_angle) * x + (u * v * (1 - cos_angle) - w * sin_angle) * y + (u * w * (1 - cos_angle) + v * sin_angle) * z;
    double new_y = (u * v * (1 - cos_angle) + w * sin_angle) * x + (v * v + (1 - v * v) * cos_angle) * y + (v * w * (1 - cos_angle) - u * sin_angle) * z;
    double new_z = (u * w * (1 - cos_angle) - v * sin_angle) * x + (v * w * (1 - cos_angle) + u * sin_angle) * y + (w * w + (1 - w * w) * cos_angle) * z;

    axis_direction_ = Vector(new_x, new_y, new_z).normalized();
}

bool Cone::intersect(const Ray& ray, Intersection& intersection)
{
    Vector oc = ray.origin() - apex_;
    double cos_angle = cos(angle_);
    double a = dot(ray.direction() - axis_direction_ * dot(ray.direction(), axis_direction_), ray.direction() - axis_direction_ * dot(ray.direction(), axis_direction_)) - cos_angle * cos_angle * dot(ray.direction(), ray.direction());
    double b = 2.0 * (dot(ray.direction() - axis_direction_ * dot(ray.direction(), axis_direction_), oc - axis_direction_ * dot(oc, axis_direction_)) - cos_angle * cos_angle * dot(ray.direction(), oc));
    double c = dot(oc - axis_direction_ * dot(oc, axis_direction_), oc - axis_direction_ * dot(oc, axis_direction_)) - cos_angle * cos_angle * dot(oc, oc);
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double temp = (-b - sqrt(discriminant)) / (2.0 * a);
        double intersect_y = dot(ray.at(temp) - apex_, axis_direction_);
        if (temp > 0 && intersect_y > 0 && intersect_y < 1.0) {
            intersection.setT(temp);
            intersection.setPosition(ray.at(temp));
            Vector normal = unit_vector(intersection.getPosition() - (apex_ + intersect_y * axis_direction_));
            intersection.setNormal(normal);
            intersection.setColor(color_);
            return true;
        }
    }
    double t_base = -dot(ray.origin() - (apex_ + height_ * axis_direction_), axis_direction_) / dot(ray.direction(), axis_direction_);
    if (t_base > 0) {
        Point base_intersection = ray.at(t_base);
        Vector base_to_intersection = base_intersection - (apex_ + height_ * axis_direction_);
        double distance_squared = base_to_intersection.length_squared();
        double base_radius_squared = tan(angle_) * tan(angle_) * height_ * height_;
        if (distance_squared <= base_radius_squared) {
            intersection.setT(t_base);
            intersection.setPosition(base_intersection);
            intersection.setNormal(axis_direction_);
            intersection.setColor(color_);
            return true;
        }
    }
    return false;
}


extern "C" std::unique_ptr<Cone> create_cone(const Point& apex, const Vector& axis_direction, double angle, double height, const Color& color, const Vector& rotation_axis, double rotation_angle_deg)
{
    return std::make_unique<Cone>(apex, axis_direction, angle, height, color, rotation_axis, rotation_angle_deg);
}
