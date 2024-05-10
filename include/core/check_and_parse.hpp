/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** check_and_parse
*/

#ifndef CHECK_AND_PARSE_HPP_
#define CHECK_AND_PARSE_HPP_

#include <iostream>
#include <vector>
#include <memory>
#include "Interfaces/IPrimitive.hpp"
#include "Interfaces/ILight.hpp"
#include "Lights/AmbientLight.hpp"

class check_and_parse {
    public:
        check_and_parse(int ac, std::string);
        int parse(std::string scene_file);
        const std::vector<std::pair<std::string, std::shared_ptr<Primitive>>>& getPrimitivesVector() const { return primitivesVector; }
        const std::vector<std::shared_ptr<DirectionalLight>>& getDirectionalVector() const { return directionalVector; }
        std::vector<std::pair<std::string, int>> getCameraPos() { return camera_pos;}
        std::vector<std::pair<std::string, int>> getCameraResolution() { return camera_resolution;}
        std::vector<std::pair<std::string, int>> getCameraRotation() { return camera_rotation;}
        int getIntensity() { return directional_intensity; }
        double getAmbient() { return ambient_light; }

    private:
        std::vector<std::pair<std::string, std::shared_ptr<Primitive>>> primitivesVector;
        // std::vector<std::shared_ptr<Light>> _light;
        std::vector<std::pair<std::string, int>> camera_pos;
        std::vector<std::pair<std::string, int>> camera_resolution;
        std::vector<std::pair<std::string, int>> camera_rotation;
        DirectionalLight _light;
        std::vector<std::shared_ptr<DirectionalLight>> directionalVector;
        int camera_fov = 0;
        int ambient_light = 0;
        int directional_intensity = 0;
};

#endif /* !CHECK_AND_PARSE_HPP_ */
