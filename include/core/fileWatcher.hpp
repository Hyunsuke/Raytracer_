/*
** EPITECH PROJECT, 2023
** raytracer_actual
** File description:
** fileWatcher.hpp
*/

#include <iostream>
#include <libconfig.h++>
#include <sys/inotify.h>
#include <unistd.h>
#include <string>
#include <functional>
#include <thread>
#include <sys/stat.h>

class FileWatcher {
public:
    FileWatcher(std::string filePath) : filePath(filePath) {
        if (stat(filePath.c_str(), &fileInfo) != 0) {
            std::cerr << "Error: Unable to get file information." << std::endl;
            return;
        }
    }

    bool fileModified() {
        struct stat newInfo;
        if (stat(filePath.c_str(), &newInfo) != 0) {
            std::cerr << "Error: Unable to get file information." << std::endl;
            return false;
        }
        if (newInfo.st_mtime != fileInfo.st_mtime) {
            fileInfo = newInfo;
            return true;
        }
        return false;
    }
    private:
    std::string filePath;
    struct stat fileInfo;
};