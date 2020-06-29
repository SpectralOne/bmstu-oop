#pragma once

#include "base_canvas.hpp"
#include "math3d/point3d.hpp"

class BaseDrawer {
   public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void drawLine(const Point3D<double>&, const Point3D<double>&) = 0;
    virtual void setCanvas(std::shared_ptr<BaseCanvas> canvas) = 0;

    std::shared_ptr<BaseCanvas> _canvas;
};
