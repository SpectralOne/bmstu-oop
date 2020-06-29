#pragma once

#include "math3d/point3d.hpp"

class BaseCanvas {
   public:
    virtual void addLine(const Point3D<double> &p1, const Point3D<double> &p2) = 0;
};
