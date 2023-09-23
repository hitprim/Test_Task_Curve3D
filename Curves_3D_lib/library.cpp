#include "library.h"

Circle3D::Circle3D(double radius) : m_radius(radius) {
    if (radius <= 0) {
        throw std::invalid_argument("Radius must be positive");
    }
}

std::tuple<double, double, double> Circle3D::CalculatePoint(double t) const {
    double x, y, z;
    x = m_radius * cos(t);
    y = m_radius * sin(t);
    z = 0.0;
    return std::make_tuple(x, y, z);
}

std::tuple<double, double, double> Circle3D::CalculateDerivative(double t) const {
    double dx, dy, dz;
    dx = -m_radius * sin(t);
    dy = m_radius * cos(t);
    dz = 0.0;
    return std::make_tuple(dx, dy, dz);
}

Ellipse::Ellipse(double x, double y) : m_radiusX(x), m_radiusY(y) {
    if (x <= 0 || y <= 0) {
        throw std::invalid_argument("Radii must be positive");
    }
}

std::tuple<double, double, double> Ellipse::CalculatePoint(double t) const {
    double x, y, z;
    x = m_radiusX * cos(t);
    y = m_radiusY * sin(t);
    z = 0.0;
    return std::make_tuple(x, y, z);
}

std::tuple<double, double, double> Ellipse::CalculateDerivative(double t) const {
    double dx, dy, dz;
    dx = -m_radiusX * sin(t);
    dy = m_radiusY * cos(t);
    dz = 0.0;
    return std::make_tuple(dx, dy, dz);
}

Helix::Helix(double radius, double step) : m_radius(radius), m_step(step) {
    if (radius <= 0 || step <= 0) {
        throw std::invalid_argument("Radius and step must be positive");
    }
}

std::tuple<double, double, double> Helix::CalculatePoint(double t) const {
    double x, y, z;
    x = m_radius * cos(t);
    y = m_radius * sin(t);
    z = m_step * t / (2 * M_PI);
    return std::make_tuple(x, y, z);
}

std::tuple<double, double, double> Helix::CalculateDerivative(double t) const {
    double dx, dy, dz;
    dx = -m_radius * sin(t);
    dy = m_radius * cos(t);
    dz = m_step / (2 * M_PI);
    return std::make_tuple(dx, dy, dz);
}
