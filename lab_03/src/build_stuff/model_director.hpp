#pragma once

#include <memory>

#include "base_model_builder.hpp"
#include "load/source_loader.hpp"
#include "objects/model/model.hpp"

class ModelDirector {
   public:
    std::shared_ptr<Model> build(const Vector<Point3D<double>>& points, const Vector<Edge>& edges);
    void setBuilder(std::shared_ptr<BaseModelBuilder> builder);

   private:
    std::shared_ptr<BaseModelBuilder> _builder;
};
