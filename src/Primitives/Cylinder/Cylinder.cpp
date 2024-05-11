/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere.cpp
*/

#include "../../../include/Primitives/Cylinder.hpp"

Cylinder::Cylinder(const Point& base_center, const Vector &axis_direction, double radius, double height, const Color &color, const Vector& rotation_axis, double rotation_angle_deg)
        : base_center_(base_center), axis_direction_(axis_direction), radius_(radius), height_(height), color_(color)
{
    rotate(rotation_angle_deg, rotation_axis);
}

void Cylinder::rotate(double angle, const Vector& axis)
{
    double angle_rad = angle * M_PI / 180.0;
    double cos_angle = cos(angle_rad);
    double sin_angle = sin(angle_rad);
    double u = axis.x;
    double v = axis.y;
    double w = axis.z;

    // Rotate axis_direction_
    double new_x_axis = axis_direction_.x * (u * u + (1 - u * u) * cos_angle) + axis_direction_.y * (u * v * (1 - cos_angle) - w * sin_angle) + axis_direction_.z * (u * w * (1 - cos_angle) + v * sin_angle);
    double new_y_axis = axis_direction_.x * (u * v * (1 - cos_angle) + w * sin_angle) + axis_direction_.y * (v * v + (1 - v * v) * cos_angle) + axis_direction_.z * (v * w * (1 - cos_angle) - u * sin_angle);
    double new_z_axis = axis_direction_.x * (u * w * (1 - cos_angle) - v * sin_angle) + axis_direction_.y * (v * w * (1 - cos_angle) + u * sin_angle) + axis_direction_.z * (w * w + (1 - w * w) * cos_angle);
    axis_direction_ = Vector(new_x_axis, new_y_axis, new_z_axis);

    if (axis == Vector(1.0, 0.0, 0.0)) {
        double new_y_base = base_center_.y * cos_angle - base_center_.z * sin_angle;
        double new_z_base = base_center_.y * sin_angle + base_center_.z * cos_angle;
        base_center_ = Point(base_center_.x, new_y_base, new_z_base);

        double descend_distance = (1 - cos_angle) * (base_center_.y + height_ / 2.0) * 3;
        double avancing_distance = sin_angle * (base_center_.y + height_ / 3.0);
        base_center_ = Point(base_center_.x, base_center_.y - descend_distance, base_center_.z - avancing_distance);
    }
}

bool Cylinder::intersect(const Ray& ray, Intersection& intersection)
{
    Vector oc = ray.origin() - base_center_;
    double a = dot(ray.direction() - axis_direction_ * dot(ray.direction(), axis_direction_), ray.direction() - axis_direction_ * dot(ray.direction(), axis_direction_));
    double b = 2.0 * dot(ray.direction() - axis_direction_ * dot(ray.direction(), axis_direction_), oc - axis_direction_ * dot(oc, axis_direction_));
    double c = dot(oc - axis_direction_ * dot(oc, axis_direction_), oc - axis_direction_ * dot(oc, axis_direction_)) - radius_ * radius_;
    double discriminant = b * b - 4 * a * c;
    if (discriminant >= 0) {
        double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
        double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
        double t = (t1 > 0) ? t1 : t2;
        double intersect_y = dot(ray.at(t) - base_center_, axis_direction_);
        if (intersect_y >= 0 && intersect_y <= height_) {
            intersection.setT(t);
            intersection.setPosition(ray.at(t));
            Vector normal;
            if (intersect_y < 0.0001 || height_ - intersect_y < 0.0001) {
                normal = axis_direction_;
            } else {
                normal = unit_vector(intersection.getPosition() - (base_center_ + intersect_y * axis_direction_));
            }
            intersection.setNormal(normal);
            intersection.setColor(color_);
            return true;
        }
    }
    double t_cap = (height_ - dot(ray.origin() - base_center_, axis_direction_)) / dot(ray.direction(), axis_direction_);
    if (t_cap > 0) {
        Point cap_intersection = ray.at(t_cap);
        double dist_to_axis = (cap_intersection - (base_center_ + height_ * axis_direction_)).length();
        if (dist_to_axis <= radius_) {
            intersection.setT(t_cap);
            intersection.setPosition(cap_intersection);
            intersection.setNormal(unit_vector(cap_intersection - (base_center_ + height_ * axis_direction_)));
            intersection.setColor(color_);
            return true;
        }
    }
    t_cap = -dot(ray.origin() - base_center_, axis_direction_) / dot(ray.direction(), axis_direction_);
    if (t_cap > 0) {
        Point cap_intersection = ray.at(t_cap);
        double dist_to_axis = (cap_intersection - base_center_).length();
        if (dist_to_axis <= radius_) {
            intersection.setT(t_cap);
            intersection.setPosition(cap_intersection);
            intersection.setNormal(-1.0 * unit_vector(cap_intersection - base_center_));
            intersection.setColor(color_);
            return true;
        }
    }
    return false;
}

std::unique_ptr<Cylinder> create_cylinder(const Point& base_center, const Vector& axis_direction, double radius, double height, const Color& color, const Vector& rotation_axis, double rotation_angle_deg)
{
    return std::make_unique<Cylinder>(base_center, axis_direction, radius, height, color, rotation_axis, rotation_angle_deg);
}