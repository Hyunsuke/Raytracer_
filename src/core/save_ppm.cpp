/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** save_ppm.cpp
*/

#include "raytracer.hpp"

void Raytracer::save_ppm() {
    std::ofstream outFile("src/screenshots/last_screenshot.ppm");
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