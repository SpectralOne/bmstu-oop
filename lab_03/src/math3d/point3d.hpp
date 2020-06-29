#pragma once

#include <istream>
#include <memory>

#include "../containers/matrix/matrix.hpp"

template <typename T>
class Point3D {
   public:
    explicit Point3D();
    explicit Point3D(const T& x, const T& y, const T& z);
    Point3D(const Point3D& other);
    Point3D& operator=(const Point3D& rhs);

    T getX() const;
    T getY() const;
    T getZ() const;

    void setX(T x);
    void setY(T y);
    void setZ(T z);

    void transform(const std::shared_ptr<matrix<T>> mtr);

    Point3D& operator+=(const Point3D&);
    Point3D& operator+=(const T&);
    Point3D& operator-=(const Point3D&);
    Point3D& operator-=(const T&);
    Point3D& operator*=(const Point3D&);
    Point3D& operator*=(const T&);
    Point3D& operator/=(const Point3D&);
    Point3D& operator/=(const T&);

   private:
    T _x, _y, _z;
};

template <typename T>
std::istream& operator>>(std::istream& is, Point3D<T>& point);

#include "_point3d.hpp"
