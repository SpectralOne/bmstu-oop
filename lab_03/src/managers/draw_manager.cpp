#include "draw_manager.hpp"

#include <ctime>

#include "../exceptions/draw_exception.hpp"
#include "math3d/transform_matrix.h"

void DrawManager::proectPoint(Point3D<double> &point) {
    Point3D<double> cam_pos(camera_->getPosition());
    std::shared_ptr<matrix<double>> transform_matrix(std::make_shared<MoveMatrix>(-cam_pos.getX(), -cam_pos.getY(), 0));
    point.transform(transform_matrix);
    transform_matrix.reset(new RotateOxMatrix(-camera_->getXAngle()));
    point.transform(transform_matrix);
    transform_matrix.reset(new RotateOyMatrix(-camera_->getYAngle()));
    point.transform(transform_matrix);
    transform_matrix.reset(new RotateOzMatrix(-camera_->getZAngle()));
    point.transform(transform_matrix);

    double eps = 1e-10;
    double znam = point.getZ() + cam_pos.getZ();
    if (znam < eps && znam > -eps) {
        znam = eps;
    }
    double distCoef = cam_pos.getZ() / znam;
    point.setX(point.getX() * distCoef);
    point.setY(point.getY() * distCoef);
}

void DrawManager::setDrawer(std::shared_ptr<BaseDrawer> drawer) {
    _drawer = drawer;
}

void DrawManager::setCamera(std::shared_ptr<Camera> camera) {
    camera_ = camera;
}

void DrawManager::visit(Model &model) {
    time_t t_time = time(NULL);
    if (!_drawer) {
        throw DrawerError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    if (!camera_) {
        throw CameraError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    auto mesh = model.getMesh();
    auto lines = mesh->getLines();

    for (auto &line : lines) {
        proectPoint(line.get_first());
        proectPoint(line.get_second());
        _drawer->drawLine(line.get_first(), line.get_second());
    }
}

void DrawManager::visit(Camera &camera) {}

void DrawManager::visit(CompositeObject &composite) {}
