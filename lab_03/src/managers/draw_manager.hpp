#pragma once

#include <QGraphicsScene>

#include "../draw/visitor.hpp"
#include "base_manager.hpp"
#include "containers/matrix/matrix.hpp"
#include "draw/base_drawer.hpp"
#include "scene/scene.hpp"

class DrawManager : public BaseManager, public Visitor {
   public:
    void setDrawer(std::shared_ptr<BaseDrawer> drawer);
    void setCamera(std::shared_ptr<Camera> camera);
    void visit(Model &model);
    void visit(Camera &model);
    void visit(CompositeObject &model);

   private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera> camera_;
    void proectPoint(Point3D<double> &point);
};
