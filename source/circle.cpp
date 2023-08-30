#include "../stdafx.h"
#include "circle.h"

Circle::Circle(double radius)
{
    r = radius;
}

double Circle::radius() const
{
    return r;
}

double Circle::step() const
{
    return 0.0; // �� ������������ ��� ������
}

double Circle::length() const
{
    return 2.0 * M_PI * r;
}

double Circle::curvature() const
{
    return 1.0 / r;
}

void Circle::evaluate(double t, double& x, double& y, double& z) const
{
    x = r * cos(t);
    y = r * sin(t);
    z = 0.0;
}

void Circle::derivative(double t, double& dx, double& dy, double& dz) const
{
    dx = -r * sin(t);
    dy = r * cos(t);
    dz = 0.0;
}