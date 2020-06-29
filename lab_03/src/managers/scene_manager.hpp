#pragma once

#include "base_manager.hpp"
#include "scene/scene.hpp"

class SceneManager : public BaseManager {
   public:
    SceneManager();

    std::shared_ptr<Scene> getScene();
    void setCurrentCamera(std::string name);
    std::shared_ptr<Camera> getCurrentCamera();

   private:
    std::shared_ptr<Scene> scene;
    std::shared_ptr<Camera> current_camera;
};
