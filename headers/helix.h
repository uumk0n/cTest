#pragma once
#include "curve.h"
class Helix : public Curve3D
{
private:
    double r, s;

public:
    Helix(double radius, double step);

    double radius() const override;

    double step() const override;

    double length() const override;

    double curvature() const override;

    void evaluate(double t, double& x, double& y, double& z) const override;

    void derivative(double t, double& dx, double& dy, double& dz) const override;
};