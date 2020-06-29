#pragma once

#include <QGraphicsScene>

#include <memory>

#include "base_canvas.hpp"

class QtCanvas : public BaseCanvas {
   public:
    void addLine(const Point3D<double> &p1, const Point3D<double> &p2) override;
    explicit QtCanvas(std::shared_ptr<QGraphicsScene> canvas);

   private:
    std::shared_ptr<QGraphicsScene> _scene;
};
