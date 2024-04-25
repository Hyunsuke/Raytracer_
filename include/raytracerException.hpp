/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** raytracerException.hpp
*/

#ifndef RAYTRACER_EXCEPTION_HPP
    #define RAYTRACER_EXCEPTION_HPP

#include <exception>
#include <string>

class RaytracerException : public std::exception {
public:
    RaytracerException(const std::string& name, const std::string& type) : _message(name), _type(type) {}

    const std::string& getName() const {
        return _message;
    }

    const std::string& getType() const { return _type; }
    const char *what() const noexcept override { return _message.c_str(); }

private:
    std::string _message;
    std::string _type;
};

#endif //RAYTRACER_EXCEPTION_HPP
