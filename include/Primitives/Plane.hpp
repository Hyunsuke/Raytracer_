/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Plane
*/

#ifndef PLANE_HPP_
#define PLANE_HPP_

#include "../Interfaces/IPrimitive.hpp"
#include "../Utilities/Point.hpp"
#include "../Utilities/Ray.hpp"
#include "../Utilities/Intersection.hpp"
#include <memory>

class Plane : public Primitive {
    public:
        Plane() = default; // Parser constructor
        ~Plane() {}; // Destructor
        Plane(const char axis, double position, const Color& color);
        bool intersect(const Ray& ray, Intersection& intersection) const override;
        void setAxis(std::string axis) { _axis = axis; }
        void setPosition(double pos) { _pos = pos;}
        void setColorR(int cR) { _color_r = cR; }
        void setColorG(int cG) { _color_g = cG; }
        void setColorB(int cB) { _color_b = cB; }
        char getAxis() {
            if (_axis.empty())
                return 'Z';
            if (_axis[0] != 'X' && _axis[0] != 'Y' && _axis[0] != 'Z')
                return 'Z';
            return _axis[0];
        }
        double getPosition() { return _pos;}
        int getColorR() { return _color_r; }
        int getColorG() { return _color_g; }
        int getColorB() { return _color_b; }

    private:
        std::string _axis = "Z";
        double _pos = 0;
        int _color_r = 0;
        int _color_g = 0;
        int _color_b = 0;
    // 16 private
        char axis_;
        double position_;
        Color color_;
};
extern "C" std::unique_ptr<Plane> create_plane(const char axis, double position, const Color& color);

#endif /* !PLANE_HPP_ */
