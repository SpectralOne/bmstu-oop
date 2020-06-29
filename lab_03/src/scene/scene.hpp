#pragma once

#include <memory>

#include "objects/composite/composite_object.hpp"

class Scene {
   public:
    Scene();

    void Add(std::shared_ptr<SceneObject> object);
    void Remove(IteratorObject& it);
    std::shared_ptr<SceneObject> getObject(std::string object);
    std::shared_ptr<CompositeObject> getObject();

   private:
    std::shared_ptr<CompositeObject> _object;
};
