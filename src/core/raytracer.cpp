/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** raytracer.cpp
*/

#include "raytracer.hpp"

Raytracer::Raytracer(std::string _file, check_and_parse &parse) : file(_file), _parse(parse)
{
    load_sphere_library("src/plugins/libsphere.so");
    load_cylinder_library("src/plugins/libcylinder.so");
    load_plane_library("src/plugins/libplane.so");
    load_cone_library("src/plugins/libcone.so");
}

Raytracer::~Raytracer()
{
    vertices.clear();
    image.clear();
}

Color Raytracer::ray_color(const Ray& r)
{
    Intersection intersection;

    if (sphereManager.findClosestIntersection(r, intersection) ||
        cylinderManager.findClosestIntersection(r, intersection) ||
        coneManager.findClosestIntersection(r, intersection) ||
        planeManager.findClosestIntersection(r, intersection)) {
        return intersection.getColor() / 255;
    } else {
        Vector unit_direction = unit_vector(r.direction());
        double t = 0.5 * (unit_direction.y + 1.0);
        return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
    }
}

int getCameraInfos(std::vector<std::pair<std::string, int>> camera_info, std::string key)
{
    for (size_t i = 0; i < camera_info.size(); i++) {
        if (camera_info[i].first == key)
            return camera_info[i].second;
    }
    return 0;
}

void Raytracer::run()
{

    std::vector<std::pair<std::string, std::shared_ptr<Primitive>>> primitiveVector = _parse.getPrimitivesVector();

    for (size_t i = 0; i < primitiveVector.size(); ++i) {
        if (primitiveVector[i].first == "Sphere") {
            std::shared_ptr<Sphere> SpherePtr = std::dynamic_pointer_cast<Sphere>(primitiveVector[i].second);
            sphereManager.addPrimitive(create_sphere_instance(Point
            (SpherePtr->getX(), SpherePtr->getY(), SpherePtr->getZ()),
            SpherePtr->getR(), Color(SpherePtr->getcR(), SpherePtr->getcG(), SpherePtr->getcB())));
        }
        if (primitiveVector[i].first == "Plane") {
            std::shared_ptr<Plane> PlanePtr = std::dynamic_pointer_cast<Plane>(primitiveVector[i].second);
            planeManager.addPrimitive(create_plane_instance(PlanePtr->getAxis(), PlanePtr->getPosition(),
            Color(PlanePtr->getColorR(), PlanePtr->getColorG(), PlanePtr->getColorB())));
        }
        if (primitiveVector[i].first == "Cylinder") {
            std::shared_ptr<Cylinder> CylinderPtr = std::dynamic_pointer_cast<Cylinder>(primitiveVector[i].second);
            cylinderManager.addPrimitive(create_cylinder_instance(Point
            (CylinderPtr->getPosX(), CylinderPtr->getPosY(), CylinderPtr->getPosZ()),
            Vector(CylinderPtr->getAxisX(), CylinderPtr->getAxisY(), CylinderPtr->getAxisZ()),
            CylinderPtr->getR(), CylinderPtr->getHeight(),
            Color(CylinderPtr->getcR(), CylinderPtr->getcG(), CylinderPtr->getcB())));
        }
        if (primitiveVector[i].first == "Cone") {
            std::shared_ptr<Cone> ConePtr = std::dynamic_pointer_cast<Cone>(primitiveVector[i].second);
            coneManager.addPrimitive(create_cone_instance(Point
            (ConePtr->getPosX(), ConePtr->getPosY(), ConePtr->getPosZ()),
            Vector(ConePtr->getAxisX(), ConePtr->getAxisY(), ConePtr->getAxisZ()),
            M_PI / ConePtr->getAngle(), ConePtr->getHeight(),
            Color(ConePtr->getcR(), ConePtr->getcG(), ConePtr->getcB())));
        }
    }

    this->image_width = getCameraInfos(_parse.getCameraResolution(), "width");
    image_height = getCameraInfos(_parse.getCameraResolution(), "height");
    image = std::vector<std::vector<Color>>(image_height, std::vector<Color>(image_width));
    this->_window.create(sf::VideoMode(image_width, image_height), "raytracer");
    Camera.Set_X(getCameraInfos(_parse.getCameraPos(), "x"));
    Camera.Set_Y(getCameraInfos(_parse.getCameraPos(), "y"));
    Camera.Set_Z(getCameraInfos(_parse.getCameraPos(), "z"));
    vertices = create_map();

    while (this->_window.isOpen())
        WindowLoop();
    save_ppm();
}