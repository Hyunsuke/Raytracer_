/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** save_ppm.cpp
*/

#include "raytracer.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

bool file_exists(const std::string& filename)
{
    std::ifstream file(filename);
    return file.good();
}

std::string get_unique_filename(const std::string& base_filename)
{
    if (!file_exists(base_filename + ".ppm")) {
        return base_filename;
    }

    // Trouver le premier numéro disponible
    int number = 1;
    std::string new_filename;
    while (true) {
        std::ostringstream oss;
        oss << base_filename << "_" << number;
        new_filename = oss.str();
        if (!file_exists(new_filename + ".ppm")) {
            break;
        }
        ++number;
    }

    return new_filename;
}

void Raytracer::save_ppm()
{
    std::string base_filename = "src/screenshots/last_screenshot";
    std::string filename = get_unique_filename(base_filename);
    filename += ".ppm";
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Impossible d'ouvrir le fichier pour l'écriture.\n";
        return;
    }
    outFile << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            Color& pixel_color = image[j][i];
            pixel_color.write_color(outFile, pixel_color);
        }
    }
    outFile.close();
}
