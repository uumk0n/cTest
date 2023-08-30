#include "../stdafx.h"
#include "helix.h"

Helix::Helix(double radius, double step)
{
    r = radius;
    s = step;
}

double Helix::radius() const
{
    return r;
}

double Helix::step() const {
    return s;
}

double Helix::length() const
{
    return 2.0 * M_PI * r;
}

double Helix::curvature() const
{
    return 1.0 / r;
}

void Helix::evaluate(double t, double& x, double& y, double& z) const
{
    x = r * cos(t);
    y = r * sin(t);
    z = s * t / (2.0 * M_PI);
}

void Helix::derivative(double t, double& dx, double& dy, double& dz) const
{
    dx = -r * sin(t);
    dy = r * cos(t);
    dz = s / (2.0 * M_PI);
}