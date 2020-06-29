#pragma once

#include "objects/scene_object.hpp"

class InvisibleObject : public SceneObject {
   public:
    explicit InvisibleObject() = default;
    ~InvisibleObject() = default;

    bool Visible() const final;
};
