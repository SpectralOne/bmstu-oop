#pragma once

#include "containers/matrix/matrix.hpp"
#include "containers/vector/vector.hpp"
#include "draw/visitor.hpp"
#include "math3d/edge.hpp"
#include "math3d/point3d.hpp"
#include "mesh.hpp"
#include "visible_object.hpp"

class Model : public VisibleObject {
   public:
    Model() = default;
    explicit Model(std::string name);
    Model(const Model&);
    Model(Model&&) noexcept;
    ~Model() = default;

    Model& operator=(const Model&);
    Model& operator=(Model&&) noexcept;
    void transform(const std::shared_ptr<matrix<double>> mtr) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

    std::shared_ptr<Mesh> getMesh();
    void add(const Vector<Point3D<double>>& points);
    void add(const Vector<Edge>& edges);

   private:
    std::shared_ptr<Mesh> _mesh;
};
