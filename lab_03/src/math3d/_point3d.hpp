#include "../containers/vector/vector.hpp"

template <typename T>
Point3D<T>::Point3D()
    : _x(0), _y(0), _z(0) {}

template <typename T>
Point3D<T>::Point3D(const T& x, const T& y, const T& z)
    : _x(x), _y(y), _z(z) {}

template <typename T>
Point3D<T>::Point3D(const Point3D<T>& other)
    : Point3D(other._x, other._y, other._z) {}

template <typename T>
Point3D<T>& Point3D<T>::operator=(const Point3D<T>& rhs) {
    _x = rhs._x;
    _y = rhs._y;
    _z = rhs._z;

    return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator+=(const Point3D<T>& pnt) {
    _x += pnt._x;
    _y += pnt._y;
    _z += pnt._z;

    return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator+=(const T& value) {
    _x += value;
    _y += value;
    _z += value;

    return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator-=(const Point3D<T>& rhs) {
    _x -= rhs._x;
    _y -= rhs._y;
    _z -= rhs._z;

    return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator-=(const T& value) {
    _x -= value;
    _y -= value;
    _z -= value;

    return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator*=(const Point3D<T>& rhs) {
    _x *= rhs._x;
    _y *= rhs._y;
    _z *= rhs._z;

    return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator*=(const T& value) {
    _x *= value;
    _y *= value;
    _z *= value;

    return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator/=(const Point3D<T>& rhs) {
    _x /= rhs._x;
    _y /= rhs._y;
    _z /= rhs._z;

    return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator/=(const T& value) {
    _x /= value;
    _y /= value;
    _z /= value;

    return *this;
}

template <typename T>
T Point3D<T>::getX() const {
    return _x;
}

template <typename T>
T Point3D<T>::getY() const {
    return _y;
}

template <typename T>
T Point3D<T>::getZ() const {
    return _z;
}

template <typename T>
void Point3D<T>::setX(T x) {
    _x = x;
}

template <typename T>
void Point3D<T>::setY(T y) {
    _y = y;
}

template <typename T>
void Point3D<T>::setZ(T z) {
    _z = z;
}

template <typename T>
void Point3D<T>::transform(const std::shared_ptr<matrix<T>> mtr) {
    Vector<T> result(4, 0);
    Vector<T> data = {_x, _y, _z, 1.0};
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            result[i] += data[j] * (*mtr)[i][j];
        }
    }

    this->setX(result[0]);
    this->setY(result[1]);
    this->setZ(result[2]);
}

template <typename T>
std::istream& operator>>(std::istream& is, Point3D<T>& point) {
    T x, y, z;
    is >> x >> y >> z;
    point.setX(x);
    point.setY(y);
    point.setZ(z);

    return is;
}
