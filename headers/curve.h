#pragma once
class Curve3D {
public:
    virtual ~Curve3D() {}
    virtual double radius() const = 0;
    virtual double step() const = 0;
    virtual double length() const = 0;
    virtual double curvature() const = 0;
    virtual void evaluate(double t, double& x, double& y, double& z) const = 0;
    virtual void derivative(double t, double& dx, double& dy, double& dz) const = 0;
};