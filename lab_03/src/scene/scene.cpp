#include "scene.hpp"

#include <memory.h>

#include "containers/vector/iterator/iterator.hpp"

#include "exceptions/scene_exception.hpp"

Scene::Scene() : _object(new CompositeObject) {}

void Scene::Add(std::shared_ptr<SceneObject> object) {
    _object->add(std::move(object));
}

void Scene::Remove(IteratorObject& it) {
    _object->remove(it);
}

std::shared_ptr<CompositeObject> Scene::getObject() {
    return _object;
}

std::shared_ptr<SceneObject> Scene::getObject(std::string object) {
    auto it = _object->begin();
    auto it_e = _object->end();
    bool flag = true;
    while (it != it_e && flag) {
        auto t = it.get();
        if (it.get()->getName() == object) {
            flag = false;
        }
        if (flag) {
            ++it;
        }
    }
    if (flag) {
        time_t t_time = time(NULL);
        throw ObjectError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return it.get();
}
