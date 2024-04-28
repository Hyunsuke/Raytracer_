/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** check_and_parse.cpp
*/

#include "raytracer.hpp"

int parse(std::string scene_file)
{
    libconfig::Config cfg;

    try
    {
        cfg.readFile(scene_file);

        const libconfig::Setting& camera = cfg.lookup("camera");
        const libconfig::Setting& resolution = camera.lookup("resolution");
        int width, height;
        resolution.lookupValue("width", width);
        resolution.lookupValue("height", height);
        std::cout << "Resolution: " << width << "x" << height << std::endl;

        const libconfig::Setting& primitives = cfg.lookup("primitives");
        const libconfig::Setting& spheres = primitives.lookup("spheres");
        for (int i = 0; i < spheres.getLength(); ++i)
        {
            int x, y, z, r;
            const libconfig::Setting& sphere = spheres[i];
            sphere.lookupValue("x", x);
            sphere.lookupValue("y", y);
            sphere.lookupValue("z", z);
            sphere.lookupValue("r", r);
            std::cout << "Sphere " << i+1 << ": Position(" << x << ", " << y << ", " << z << "), Radius: " << r << std::endl;
        }
        if (spheres.getLength() == 0)
            std::cout << "No spheres found" << std::endl;

        const libconfig::Setting& lights = cfg.lookup("lights");
        double ambient, diffuse;
        lights.lookupValue("ambient", ambient);
        lights.lookupValue("diffuse", diffuse);
        std::cout << "Ambient Light: " << ambient << ", Diffuse Light: " << diffuse << std::endl;

        const libconfig::Setting& pointLights = lights.lookup("point");
        for (int i = 0; i < pointLights.getLength(); ++i)
        {
            int x, y, z;
            const libconfig::Setting& pointLight = pointLights[i];
            pointLight.lookupValue("x", x);
            pointLight.lookupValue("y", y);
            pointLight.lookupValue("z", z);
            std::cout << "Point Light " << i+1 << ": Position(" << x << ", " << y << ", " << z << ")" << std::endl;
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