#pragma once

#include "objects/scene_object.hpp"

class VisibleObject : public SceneObject {
   public:
    explicit VisibleObject() = default;
    ~VisibleObject() = default;

    bool Visible() const final;
};
