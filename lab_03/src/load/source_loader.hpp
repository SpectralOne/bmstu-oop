#pragma once

#include "containers/vector/vector.hpp"
#include "math3d/edge.hpp"
#include "math3d/point3d.hpp"

class SourceLoader {
   public:
    SourceLoader() = default;
    ~SourceLoader() noexcept = default;

    virtual void open(std::string source_name) = 0;
    virtual bool isOpen() const = 0;
    virtual void close() = 0;
    virtual Vector<Point3D<double>> readPoints() = 0;
    virtual Vector<Edge> readEdges() = 0;
};
