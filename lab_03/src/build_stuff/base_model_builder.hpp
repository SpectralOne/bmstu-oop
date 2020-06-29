#pragma once

#include "objects/model/model.hpp"

class BaseModelBuilder {
   public:
    BaseModelBuilder() = default;
    ~BaseModelBuilder() = default;
    virtual void reset(std::string name) = 0;
    virtual void buildPoints(const Vector<Point3D<double>>& points) = 0;
    virtual void buildEdges(const Vector<Edge>& edges) = 0;
    virtual std::shared_ptr<Model> getModel() = 0;
};
