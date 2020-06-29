#pragma once

#include <cmath>
#include <memory>

#include "base_manager.hpp"
#include "math3d/transform_matrix.h"
#include "objects/scene_object.hpp"
#include "scene/scene.hpp"

class TransformManager : public BaseManager {
   public:
    void moveObject(std::shared_ptr<SceneObject> obj, int dx, int dy, int dz);
    void scaleObject(std::shared_ptr<SceneObject> obj, double x, double y, double z);
    void rotateObjectOX(std::shared_ptr<SceneObject> obj, double angle);
    void rotateObjectOY(std::shared_ptr<SceneObject> obj, double angle);
    void rotateObjectOZ(std::shared_ptr<SceneObject> obj, double angle);

   private:
    double degreesToRadians(double angle);
};
