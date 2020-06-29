#pragma once

#include "containers/matrix/matrix.hpp"
#include "draw/visitor.hpp"
#include "invisible_object.hpp"
#include "math3d/point3d.hpp"

class Camera : public InvisibleObject {
   public:
    Camera(std::string name);

    const Point3D<double> &getPosition() const;
    void setPosition(const Point3D<double> &position);

    double getXAngle() const;
    void setXAngle(double x_angle);

    double getYAngle() const;
    void setYAngle(double y_angle);

    double getZAngle() const;
    void setZAngle(double z_angle);

    void transform(const std::shared_ptr<matrix<double>> mtr);
    void accept(std::shared_ptr<Visitor> visitor) override;

   private:
    Point3D<double> position;
    double x_angle;
    double y_angle;
    double z_angle;
};
