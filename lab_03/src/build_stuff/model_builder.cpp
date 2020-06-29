#include "model_builder.hpp"

void ModelBuilder::buildPoints(const Vector<Point3D<double>>& points) {
    _model->add(points);
}

void ModelBuilder::reset(std::string name) {
    _model.reset();
    _model = std::shared_ptr<Model>(std::make_shared<Model>(name));
}

void ModelBuilder::buildEdges(const Vector<Edge>& edges) {
    _model->add(edges);
}

std::shared_ptr<Model> ModelBuilder::getModel() {
    return _model;
}
