#pragma once

#include <QGraphicsScene>
#include <memory>

#include "base_drawer.hpp"
#include "math3d/point3d.hpp"

class QtDrawer : public BaseDrawer {
   public:
    QtDrawer() = default;

    void drawLine(const Point3D<double>& p1, const Point3D<double>& p2) override;
    void setCanvas(std::shared_ptr<BaseCanvas> canvas) override;
};
