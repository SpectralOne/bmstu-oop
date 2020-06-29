#pragma once

#include <fstream>

#include "containers/vector/vector.hpp"
#include "math3d/edge.hpp"
#include "source_loader.hpp"

class FileLoader : public SourceLoader {
   public:
    FileLoader() = default;
    ~FileLoader();
    void open(std::string source_name) override;
    bool isOpen() const override;
    void close() override;
    Vector<Point3D<double>> readPoints() override;
    Vector<Edge> readEdges() override;

   private:
    std::ifstream _file;
};
