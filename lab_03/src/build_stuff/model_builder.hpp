#pragma once

#include <memory>

#include "base_model_builder.hpp"
#include "load/source_loader.hpp"
#include "objects/model/model.hpp"

class ModelBuilder : public BaseModelBuilder {
   public:
    void reset(std::string name) override;
    ModelBuilder() = default;
    ~ModelBuilder() = default;
    void buildPoints(const Vector<Point3D<double>>& points) override;
    void buildEdges(const Vector<Edge>& edges) override;
    std::shared_ptr<Model> getModel() override;

   private:
    std::shared_ptr<Model> _model;
};
