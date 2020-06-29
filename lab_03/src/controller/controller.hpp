#pragma once

#include <QGraphicsScene>

#include "draw/qt_drawer.hpp"
#include "load/abstract_loader.hpp"
#include "managers/camera_manager.hpp"
#include "managers/draw_manager.hpp"
#include "managers/scene_manager.hpp"
#include "managers/transform_manager.hpp"
#include "scene/scene.hpp"

class Controller {
   public:
    static std::shared_ptr<Controller> GetInstance();
    Controller(Controller &) = delete;
    Controller(const Controller &) = delete;
    ~Controller() = default;

    void addModel(std::string model_name, std::string file_name);
    void addCamera(std::string cam_name);
    void setCamera(std::string cam_name);
    void removeCamera(std::string cam_name);
    void removeModel(std::string model_name);

    void transformCamera(std::string cam_name, Point3D<double> &move, Point3D<double> &rotate);
    void transformModel(std::string model_name, Point3D<double> &move, Point3D<double> &scale, Point3D<double> &rotate);

    void draw(std::shared_ptr<BaseDrawer> drawer);

   private:
    Controller();
    CameraManager _camera_manager;
    SceneManager _scene_manager;
    TransformManager _transform_manager;
    std::shared_ptr<AbstractLoader> _loader;
    std::shared_ptr<DrawManager> _draw_manager;
};
