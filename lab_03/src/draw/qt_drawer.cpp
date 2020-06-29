#include "qt_drawer.hpp"

#include "qt_canvas.hpp"

void QtDrawer::drawLine(const Point3D<double>& p1, const Point3D<double>& p2) {
    this->_canvas->addLine(p1, p2);
}

void QtDrawer::setCanvas(std::shared_ptr<BaseCanvas> canvas) {
    this->_canvas = canvas;
}
