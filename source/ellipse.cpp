#include "../stdafx.h"
#include "ellipse.h"

Ellipse::Ellipse(double radiusX, double radiusY)
{
    rx = radiusX;
    ry = radiusY;
}

double Ellipse::radius() const
{
    return std::max(rx, ry);
}

double Ellipse::step() const
{
    return 0.0; // не используем для эллипса
}

double Ellipse::length() const
{
    // Формула аппроксимации для периметра эллипса
    return M_PI * (3 * (rx + ry) - sqrt((3 * rx + ry) * (rx + 3 * ry)));
}

double Ellipse::curvature() const
{
    return 1.0 / std::max(rx, ry);
}

void Ellipse::evaluate(double t, double& x, double& y, double& z) const
{
    x = rx * cos(t);
    y = ry * sin(t);
    z = 0.0;
}

void Ellipse::derivative(double t, double& dx, double& dy, double& dz) const
{
    dx = -rx * sin(t);
    dy = ry * cos(t);
    dz = 0.0;
}