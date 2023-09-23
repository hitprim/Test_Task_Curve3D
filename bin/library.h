#ifndef CURVES_3D_LIBRARY_H
#define CURVES_3D_LIBRARY_H

#define LIBRARY_EXPORT __declspec(dllexport)

//
// Created by PiA on 22.09.2023.
//
#include <iostream>
#include <vector>
#include <list>
#include <cmath>

class LIBRARY_EXPORT Curve3D{
public:
    virtual ~Curve3D() = default;

    // Calculate a 3D point at parameter t
    virtual std::tuple<double, double, double> CalculatePoint(double t) const = 0;

    // Calculate the first derivative (3D vector) at parameter t
    virtual std::tuple<double, double, double> CalculateDerivative(double t) const = 0;

};

class LIBRARY_EXPORT Circle3D : public Curve3D{
private:
    double m_radius;
public:
    Circle3D(double radius);

    std::tuple<double, double, double> CalculatePoint(double t) const override;

    std::tuple<double, double, double> CalculateDerivative(double t) const override;
};

class LIBRARY_EXPORT Ellipse : public Curve3D{
private:
    double m_radiusX, m_radiusY;
public:
    Ellipse(double x, double y);

    std::tuple<double, double, double> CalculatePoint(double t) const override;

    std::tuple<double, double, double> CalculateDerivative(double t) const override;

};

class LIBRARY_EXPORT Helix : public Curve3D{
private:
    double m_radius, m_step;
public:
    Helix(double radius, double step);

    std::tuple<double, double, double> CalculatePoint(double t) const override;

    std::tuple<double, double, double> CalculateDerivative(double t) const override;
};



#endif //CURVES_3D_LIBRARY_H
