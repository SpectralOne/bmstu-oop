#include "mesh.hpp"

void Mesh::addPoints(const Vector<Point3D<double>>& points) {
    _points = points;
}

void Mesh::addEdges(const Vector<Edge>& edges) {
    _edges = edges;
}

Mesh::Mesh(const Vector<Point3D<double>>& points, const Vector<Edge>& edges) {
    _points = points;
    _edges = edges;
}

Vector<Edge>& Mesh::getEdges() {
    return _edges;
}

Vector<Point3D<double>>& Mesh::getPoints() {
    return _points;
}

void Mesh::transform(const std::shared_ptr<matrix<double>> mtr) {
    for (int i = 0; i < _points.size(); i++) {
        _points[i].transform(mtr);
    }
}

Vector<pair<Point3D<double>, Point3D<double>>> Mesh::getLines() {
    Vector<pair<Point3D<double>, Point3D<double>>> lines;
    for (int i = 0; i < _edges.size(); i++) {
        pair<Point3D<double>, Point3D<double>> tmp(_points[_edges[i].getBegin()], _points[_edges[i].getEnd()]);
        lines.push_back(tmp);
    }

    return lines;
}
