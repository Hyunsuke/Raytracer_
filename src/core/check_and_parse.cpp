/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** check_and_parse.cpp
*/

#include "raytracer.hpp"

std::shared_ptr<DirectionalLight> getDirectionalFromLights(const libconfig::Setting& pointLight)
{
    std::shared_ptr<DirectionalLight> myLight = std::make_unique<DirectionalLight>();
    double x = 0, y = 0, z = 0;
    pointLight.lookupValue("x", x);
    myLight->setX(x);
    pointLight.lookupValue("y", y);
    myLight->setY(y);
    pointLight.lookupValue("z", z);
    myLight->setZ(z);
    if (pointLight.getLength() == 0) {
        throw RaytracerException("No lights found", "check_and_parse");
    }
    return myLight;
}

std::shared_ptr<Primitive> getConeFromPrimitive(const libconfig::Setting& cone)
{
    std::shared_ptr<Cone> myCone = std::make_unique<Cone>();
    std::string axis = "Z";
    double angle = 0, height = 0;
    int pos_x = 0, pos_y = 0, pos_z = 0;
    int axis_x = 0, axis_y = 0, axis_z = 0;

    cone.lookupValue("pos_x", pos_x);
    myCone->setX(pos_x);
    cone.lookupValue("pos_y", pos_y);
    myCone->setY(pos_y);
    cone.lookupValue("pos_z", pos_z);
    myCone->setZ(pos_z);
    cone.lookupValue("axis_x", axis_x);
    myCone->setAxisX(axis_x);
    cone.lookupValue("axis_y", axis_y);
    myCone->setAxisY(axis_y);
    cone.lookupValue("axis_z", axis_z);
    myCone->setAxisZ(axis_z);
    cone.lookupValue("angle", angle);
    myCone->setAngle(angle);
    cone.lookupValue("height", height);
    myCone->setHeight(height);

    int color_r = 0, color_g = 0, color_b = 0; // Déclarer les variables pour RGB
    const libconfig::Setting& color = cone.lookup("color"); // Obtenir la sous-section de la couleur
    color.lookupValue("r", color_r);
    myCone->setColorR(color_r);
    color.lookupValue("g", color_g);
    myCone->setColorG(color_g);
    color.lookupValue("b", color_b);
    myCone->setColorB(color_b);
    if (cone.getLength() == 0) {
        throw RaytracerException("No planes found", "check_and_parse");
    }
    return myCone;
}

std::shared_ptr<Primitive> getCylinderFromPrimitive(const libconfig::Setting& cylinder)
{
    std::shared_ptr<Cylinder> myCylinder = std::make_unique<Cylinder>();
    std::string axis = "Z";
    double radius = 0, height = 0;
    int pos_x = 0, pos_y = 0, pos_z = 0;
    int axis_x = 0, axis_y = 0, axis_z = 0;

    cylinder.lookupValue("pos_x", pos_x);
    myCylinder->setX(pos_x);
    cylinder.lookupValue("pos_y", pos_y);
    myCylinder->setY(pos_y);
    cylinder.lookupValue("pos_z", pos_z);
    myCylinder->setZ(pos_z);
    cylinder.lookupValue("axis_x", axis_x);
    myCylinder->setAxisX(axis_x);
    cylinder.lookupValue("axis_y", axis_y);
    myCylinder->setAxisY(axis_y);
    cylinder.lookupValue("axis_z", axis_z);
    myCylinder->setAxisZ(axis_z);
    cylinder.lookupValue("radius", radius);
    myCylinder->setR(radius);
    cylinder.lookupValue("height", height);
    myCylinder->setHeight(height);

    int color_r = 0, color_g = 0, color_b = 0; // Déclarer les variables pour RGB
    const libconfig::Setting& color = cylinder.lookup("color"); // Obtenir la sous-section de la couleur
    color.lookupValue("r", color_r);
    myCylinder->setColorR(color_r);
    color.lookupValue("g", color_g);
    myCylinder->setColorG(color_g);
    color.lookupValue("b", color_b);
    myCylinder->setColorB(color_b);
    if (cylinder.getLength() == 0) {
        throw RaytracerException("No cylinders found", "check_and_parse");
        return nullptr;
    }
    return myCylinder;
}

std::shared_ptr<Primitive> getPlanesFromPrimitive(const libconfig::Setting& plane)
{
    std::shared_ptr<Plane> myPlane = std::make_unique<Plane>();
    std::string axis = "Z";
    double position = 0;
    plane.lookupValue("axis", axis);
    myPlane->setAxis(axis);
    plane.lookupValue("position", position);
    myPlane->setPosition(position);

    int color_r = 0, color_g = 0, color_b = 0; // Déclarer les variables pour RGB
    const libconfig::Setting& color = plane.lookup("color"); // Obtenir la sous-section de la couleur
    color.lookupValue("r", color_r);
    myPlane->setColorR(color_r);
    color.lookupValue("g", color_g);
    myPlane->setColorG(color_g);
    color.lookupValue("b", color_b);
    myPlane->setColorB(color_b);
    if (plane.getLength() == 0) {
        // std::cout << "No planes found" << std::endl;
        return nullptr;
    }
    return myPlane;
}

std::shared_ptr<Primitive> getSphereFromPrimitive(const libconfig::Setting& sphere)
{
    std::shared_ptr<Sphere> mySphere = std::make_unique<Sphere>();
    int x = 0, y = 0, z = 0;
    double r = 0;

    sphere.lookupValue("x", x);
    mySphere->setX(x);
    sphere.lookupValue("y", y);
    mySphere->setY(y);
    sphere.lookupValue("z", z);
    mySphere->setZ(z);
    sphere.lookupValue("r", r);
    mySphere->setR(r);
    // std::cout << "Sphere " << i+1 << ": Position(" << x << ", " << y << ", " << z << "), Radius: " << r << std::endl;
    int color_r = 0, color_g = 0, color_b = 0;
    const libconfig::Setting& color = sphere.lookup("color");
    color.lookupValue("r", color_r);
    mySphere->setColorR(color_r);
    color.lookupValue("g", color_g);
    mySphere->setColorG(color_g);
    color.lookupValue("b", color_b);
    mySphere->setColorB(color_b);
    if (sphere.getLength() == 0) {
        throw RaytracerException("No spheres found", "check_and_parse");
        // std::cout << "No spheres found" << std::endl;
        return nullptr;
    }
    return mySphere;
}

int check_and_parse::parse (std::string scene_file)
{
    libconfig::Config cfg;

    try
    {
        cfg.readFile(scene_file);

        const libconfig::Setting& camera = cfg.lookup("camera");

            // Camera resolution //
        const libconfig::Setting& resolution = camera.lookup("resolution");
        int width = 0, height = 0;
        resolution.lookupValue("width", width);
        resolution.lookupValue("height", height);
        camera_resolution.push_back(std::make_pair("width", width));
        camera_resolution.push_back(std::make_pair("height", height));
        if (width < 0 || height < 0)
            throw RaytracerException("Invalid camera resolution", "check_and_parse");
            // Camera Pos //
        const libconfig::Setting& position = camera.lookup("position");
        int x = 0, y = 0, z = 0;
        position.lookupValue("x", x);
        camera_pos.push_back(std::make_pair("x", x));
        position.lookupValue("y", y);
        camera_pos.push_back(std::make_pair("y", y));
        position.lookupValue("z", z);
        camera_pos.push_back(std::make_pair("z", z));
            // Camera rotation //
        const libconfig::Setting& rotation = camera.lookup("rotation");
        x = 0, y = 0, z = 0;
        rotation.lookupValue("x", x);
        camera_rotation.push_back(std::make_pair("x", x));
        rotation.lookupValue("y", y);
        camera_rotation.push_back(std::make_pair("y", y));
        rotation.lookupValue("z", z);
        camera_rotation.push_back(std::make_pair("z", z));

        //-- Get forms --//
        const libconfig::Setting& primitives = cfg.lookup("primitives");
        if (!cfg.exists("primitives"))
            return 1;

        // Sphere //
        const libconfig::Setting& spheres = primitives.lookup("spheres");
        if (primitives.exists("spheres")) {
            for (int i = 0; i < spheres.getLength(); ++i) {
                const libconfig::Setting& sphere = spheres[i];
                primitivesVector.push_back(std::make_pair("Sphere", getSphereFromPrimitive(sphere)));
            }
        }

        // Planes //
        const libconfig::Setting& planes = primitives.lookup("planes");
        if (primitives.exists("planes")) {
            for (int i = 0; i < planes.getLength(); ++i) {
                const libconfig::Setting& plane = planes[i];
                primitivesVector.push_back(std::make_pair("Plane", getPlanesFromPrimitive(plane)));
            }
        }

        // Cylinder //
        const libconfig::Setting& cylinders = primitives.lookup("cylinders");
        if (primitives.exists("cylinders")) {
            for (int i = 0; i < cylinders.getLength(); ++i) {
                const libconfig::Setting& cylinder = cylinders[i];
                primitivesVector.push_back(std::make_pair("Cylinder", getCylinderFromPrimitive(cylinder)));
            }
        }

        // Cone //
        const libconfig::Setting& cones = primitives.lookup("cones");
        if (primitives.exists("cones")) {
            for (int i = 0; i < cones.getLength(); ++i) {
                const libconfig::Setting& cone = cones[i];
                primitivesVector.push_back(std::make_pair("Cone", getConeFromPrimitive(cone)));
            }
        }

        // Lights
        const libconfig::Setting& lights = cfg.lookup("lights");
        int ambient = 0;
        lights.lookupValue("ambient", ambient);
        ambient_light = ambient;

        const libconfig::Setting& pointLights = lights.lookup("directional");
        if (lights.exists("directional")) {
            for (int i = 0; i < pointLights.getLength(); ++i) {
                const libconfig::Setting& pointLight = pointLights[i];
                directionalVector.push_back(getDirectionalFromLights(pointLight));
            }
        }
    }
    catch(const libconfig::FileIOException &fioex)
    {
        std::cerr << "I/O error while reading file." << std::endl;
        return(EXIT_FAILURE);
    }
    catch(const libconfig::ParseException &pex)
    {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
             << " - " << pex.getError() << std::endl;
        return(EXIT_FAILURE);
    }
    catch(const libconfig::SettingNotFoundException &nfex)
    {
        std::cerr << "Setting not found: " << nfex.getPath() << std::endl;
        return(EXIT_FAILURE);
    }

    return 0;
}

void print_usage()
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>\n" << std::endl;
    std::cout << "\tSCENE_FILE: scene configuration" << std::endl;
}

check_and_parse::check_and_parse(int ac, std::string filename)
{

    if (ac != 2) {
        throw RaytracerException("Invalid number of arguments, --help for information", "check_and_parse");
    }
    if (ac == 2 && std::string(filename) == "--help") {
        print_usage();
        exit(0);
    }
    if (parse(filename) == 1) {
        throw RaytracerException("Error while parsing the scene file", "check_and_parse");
    }
}