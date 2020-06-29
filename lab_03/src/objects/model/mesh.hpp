#pragma once

#include "containers/matrix/matrix.hpp"
#include "containers/pair/pair.hpp"
#include "containers/vector/vector.hpp"
#include "math3d/edge.hpp"
#include "math3d/point3d.hpp"

class Mesh {
   public:
    Mesh() = default;
    Mesh(const Vector<Point3D<double>>& points, const Vector<Edge>& edges);
    ~Mesh() = default;
    void addPoints(const Vector<Point3D<double>>& points);
    void addEdges(const Vector<Edge>& edges);
    Vector<Edge>& getEdges();
    Vector<Point3D<double>>& getPoints();
    void transform(const std::shared_ptr<matrix<double>> mtr);
    Vector<pair<Point3D<double>, Point3D<double>>> getLines();

   private:
    Vector<Point3D<double>> _points;
    Vector<Edge> _edges;
};
