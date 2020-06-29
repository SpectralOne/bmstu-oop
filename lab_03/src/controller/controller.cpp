#include "controller.hpp"

#include "build_stuff/model_builder.hpp"
#include "exceptions/scene_exception.hpp"
#include "load/file_loader.hpp"
#include "load/model_loader.hpp"

std::shared_ptr<Controller> Controller::GetInstance() {
    static std::shared_ptr<Controller> _instance(new Controller());
    return _instance;
}

Controller::Controller() : _draw_manager(std::make_shared<DrawManager>()) {
    std::shared_ptr<SourceLoader> f_loader(std::make_shared<FileLoader>());
    std::shared_ptr<BaseModelBuilder> builder(std::make_shared<ModelBuilder>());
    std::shared_ptr<AbstractLoader> m_loader(std::make_shared<ModelLoader>(f_loader, builder));
    this->_loader = m_loader;
}

void Controller::addModel(std::string name, std::string file_name) {
    std::shared_ptr<Model> model = _loader->loadModel(name, file_name);
    _scene_manager.getScene()->Add(std::shared_ptr<Model>(model));
}

void Controller::addCamera(std::string name) {
    auto camera = new Camera(name);
    _scene_manager.getScene()->Add(std::shared_ptr<Camera>(camera));
}

void Controller::setCamera(std::string cam_name) {
    _scene_manager.setCurrentCamera(cam_name);
}

void Controller::removeCamera(std::string cam_name) {
    auto scene = _scene_manager.getScene();
    IteratorObject it = scene->getObject()->begin();
    IteratorObject it_e = scene->getObject()->end();
    bool flag = true;
    while (it != it_e && flag) {
        auto tmp = *it;
        if (tmp->getName() == cam_name) {
            flag = false;
        }
        if (flag) {
            ++it;
        }
    }
    time_t t_time = time(NULL);
    if (it != it_e) {
        scene->Remove(it);
    } else {
        throw CameraError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

void Controller::removeModel(std::string model_name) {
    auto scene = _scene_manager.getScene();
    IteratorObject it = scene->getObject()->begin();
    IteratorObject it_e = scene->getObject()->end();
    bool flag = true;
    while (it != it_e && flag) {
        auto tmp = *it;
        if (tmp->getName() == model_name) {
            flag = false;
        }
        if (flag) {
            ++it;
        }
    }
    time_t t_time = time(NULL);
    if (it != it_e) {
        scene->Remove(it);
    } else {
        throw ObjectError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

void Controller::transformCamera(std::string cam_name, Point3D<double> &move, Point3D<double> &rotate) {
    auto camera = std::dynamic_pointer_cast<Camera>(_scene_manager.getScene()->getObject(cam_name));
    _transform_manager.moveObject(camera, move.getX(), move.getY(), move.getZ());
    _camera_manager.roll(camera, rotate.getX());
    _camera_manager.pitch(camera, rotate.getY());
    _camera_manager.yaw(camera, rotate.getZ());
}

void Controller::transformModel(std::string model_name, Point3D<double> &move, Point3D<double> &scale, Point3D<double> &rotate) {
    auto obj = _scene_manager.getScene()->getObject(model_name);
    _transform_manager.moveObject(obj, move.getX(), move.getY(), move.getZ());
    _transform_manager.scaleObject(obj, scale.getX(), scale.getY(), scale.getZ());
    _transform_manager.rotateObjectOX(obj, rotate.getX());
    _transform_manager.rotateObjectOY(obj, rotate.getY());
    _transform_manager.rotateObjectOZ(obj, rotate.getZ());
}

void Controller::draw(std::shared_ptr<BaseDrawer> drawer) {
    _draw_manager->setDrawer(drawer);
    _draw_manager->setCamera(_scene_manager.getCurrentCamera());
    _scene_manager.getScene()->getObject()->accept(_draw_manager);
}
