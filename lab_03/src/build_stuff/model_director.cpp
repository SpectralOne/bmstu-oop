#include "model_director.hpp"

#include <memory>

void ModelDirector::setBuilder(std::shared_ptr<BaseModelBuilder> builder) {
    _builder = std::move(builder);
}

std::shared_ptr<Model> ModelDirector::build(const Vector<Point3D<double>>& points, const Vector<Edge>& edges) {
    _builder->buildPoints(points);
    _builder->buildEdges(edges);
    return _builder->getModel();
}
