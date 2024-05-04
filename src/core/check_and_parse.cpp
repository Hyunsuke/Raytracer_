/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** check_and_parse.cpp
*/

#include "raytracer.hpp"

/*

void Lights::setValues(int x, int y, int z)
{
    _x = x;
    _y = y;
    _z = z;
}

std::shared_ptr<Light> getLightsFromLight(const libconfig::Setting& pointLight, int i)
{
    std::shared_ptr<Light> myLight = std::make_unique<Light>();
    int x = 0, y = 0, z = 0;
    pointLight.lookupValue("x", x);
    pointLight.lookupValue("y", y);
    pointLight.lookupValue("z", z);
    // myLight->setValues(x, y, z);
    std::cout << "Point Light " << i+1 << ": Position(" << x << ", " << y << ", " << z << ")" << std::endl;
    if (pointLight.getLength() == 0) {
        std::cout << "No lights found" << std::endl;
        return nullptr;
    }
    return myLight;
}
*/

std::shared_ptr<Primitive> getPlanesFromPrimitive(const libconfig::Setting& plane)
{
    std::shared_ptr<Plane> myPlane = std::make_unique<Plane>();
    std::string axis = "Z";
    int position = 0;
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
        // std::cout << "Resolution: " << width << "x" << height << std::endl;
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
            //Fov
        const libconfig::Setting& fieldOfView = camera.lookup("fieldOfView");
        fieldOfView.lookupValue("fieldOfView", camera_fov);

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
                primitivesVector.push_back(std::make_pair("Planes", getPlanesFromPrimitive(plane)));
            }
        }

    /*
        // Lights
        const libconfig::Setting& lights = cfg.lookup("lights");
        double ambient = 0, diffuse = 0;
        lights.lookupValue("ambient", ambient); // Chercher c'est quoi
        lights.lookupValue("diffuse", diffuse); // Chercher c'est quoi
        // std::cout << "Ambient Light: " << ambient << ", Diffuse Light: " << diffuse << std::endl;

        const libconfig::Setting& pointLights = lights.lookup("point");
        for (int i = 0; i < pointLights.getLength(); ++i)
        {
            const libconfig::Setting& pointLight = pointLights[i];
            _light.push_back(getLightsFromLight(pointLight, i));
        }
    */
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

check_and_parse::check_and_parse(int ac, char **av)
{

    if (ac != 2) {
        throw RaytracerException("Invalid number of arguments, --help for information", "check_and_parse");
    }
    if (ac == 2 && std::string(av[1]) == "--help") {
        print_usage();
        exit(0);
    }
    if (parse(av[1]) == 1) {
        throw RaytracerException("Error while parsing the scene file", "check_and_parse");
    }
}