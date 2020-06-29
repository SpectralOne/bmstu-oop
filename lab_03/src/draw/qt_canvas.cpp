#include "qt_canvas.hpp"

#include <QGraphicsScene>
#include <memory>

void QtCanvas::addLine(const Point3D<double> &p1, const Point3D<double> &p2) {
    _scene->addLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
}

QtCanvas::QtCanvas(std::shared_ptr<QGraphicsScene> canvas) : BaseCanvas() {
    _scene = canvas;
}
