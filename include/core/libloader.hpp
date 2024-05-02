/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** libloader
*/

#ifndef LIBLOADER_HPP_
#define LIBLOADER_HPP_

#include <dlfcn.h>
#include <memory>
#include "raytracerException.hpp"

template<typename T>
class LibraryLoader {
public:
    LibraryLoader() : handle(nullptr) {}

    ~LibraryLoader() {
        if (handle) {
            dlclose(handle);
        }
    }

    void loadLibrary(const std::string &libraryPath)
    {
        handle = dlopen(libraryPath.c_str(), RTLD_LAZY);
        if (!handle) {
            throw RaytracerException("Failed to load library", "Library");
        }
    }

    T getFunction(const std::string &functionName)
    {
        if (!handle) {
            throw RaytracerException("Library not loaded", "Function");
        }
        void* symbol = dlsym(handle, functionName.c_str());
        if (symbol == nullptr) {
            throw RaytracerException("Failed to load function", "Function");
        }
        return reinterpret_cast<T>(symbol);
    }

private:
    void* handle;
};

#endif /* !LIBLOADER_HPP_ */
