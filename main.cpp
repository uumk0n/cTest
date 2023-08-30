#include "stdafx.h"
#include "headers/circle.h"
#include "headers/ellipse.h"
#include "headers/helix.h"


int main() {
    // ������ ������ ��� �������� ������
    std::vector<Curve3D*> curves;

    // ���������� ������� ���������� �������
    for (int i = 0; i < 10; ++i) {
        double radius = (rand() % 10) + 1; // ������ �� 1 �� 10
        double step = (rand() % 10) + 1;   // ��� �� 1 �� 10
        int type = rand() % 3;             // ��������� ��� ������: 0 - Circle, 1 - Ellipse, 2 - Helix

        if (type == 0)
            curves.push_back(new Circle(radius));
        else if (type == 1)
            curves.push_back(new Ellipse(radius, radius / 2));
        else
            curves.push_back(new Helix(radius, step));
    }

    // ������� ���������� ����� � ����������� ��� t=PI/4
    double t = M_PI / 4;
    for (Curve3D* curve : curves) {
        double x, y, z;
        curve->evaluate(t, x, y, z);
        std::cout << "Point: (" << x << ", " << y << ", " << z << ") ";

        double dx, dy, dz;
        curve->derivative(t, dx, dy, dz);
        std::cout << "Derivative: (" << dx << ", " << dy << ", " << dz << ")" << std::endl;
    }

    // ���������� ������� ���������� ������� �� ������� ����������
    std::vector<Circle*> circlesOnly;
    for (Curve3D* curve : curves) {
        Circle* circle = dynamic_cast<Circle*>(curve);
        if (circle)
            circlesOnly.push_back(circle);
    }

    // ������������� ������ ��������� � ������� ����������� �������� �����������
    std::sort(circlesOnly.begin(), circlesOnly.end(), [](const Circle* a, const Circle* b) {
        return a->radius() < b->radius();
        });

    // ��������� ����� ����� �������� ���� ������ �� ������ ����������
    double totalSumOfRadii = 0.0;
    for (Circle* circle : circlesOnly) {
        totalSumOfRadii += circle->radius();
    }

    // ������ ������
    for (Curve3D* curve : curves) {
        delete curve;
    }

    // ������� ����� ����� �������� ���� ������ �� ������ ����������
    std::cout << "Total sum of radii in the second container: " << totalSumOfRadii << std::endl;

    return 0;
}
