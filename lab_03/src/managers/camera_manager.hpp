#pragma once

#include "base_manager.hpp"
#include "scene/scene.hpp"

class CameraManager : public BaseManager {
   public:
    void yaw(std::shared_ptr<Camera> camera, double angle);
    void roll(std::shared_ptr<Camera> camera, double angle);
    void pitch(std::shared_ptr<Camera> camera, double angle);
};
