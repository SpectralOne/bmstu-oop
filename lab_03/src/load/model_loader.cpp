#include "model_loader.hpp"

#include <memory.h>

#include "build_stuff/model_director.hpp"

ModelLoader::ModelLoader(std::shared_ptr<SourceLoader> ldr, std::shared_ptr<BaseModelBuilder> bld) {
    _loader = ldr;
    _builder = bld;
}

std::shared_ptr<Model> ModelLoader::loadModel(std::string model_name, std::string source_name) {
    _loader->open(source_name);
    _builder->reset(model_name);

    Vector<Point3D<double>> points = this->_loader->readPoints();
    Vector<Edge> edges = this->_loader->readEdges();
    _loader->close();

    ModelDirector director;
    director.setBuilder(_builder);

    return director.build(points, edges);
}
