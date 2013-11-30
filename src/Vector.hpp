#include <iostream>

#ifndef VECTOR_H
#define VECTOR_H

class Vector {
  protected:
    double x;
    double y;
    double z;

  public:
    Vector();

    Vector(double x, double y, double z);

    double get_x() const;
    double get_y() const;
    double get_z() const;

    Vector operator-() const;

    bool operator==(const Vector& other) const;

    Vector operator+(const Vector& other) const;

    Vector operator-(const Vector& other) const;

    Vector operator^(const Vector& other) const;

    double operator|(const Vector& other) const;

    double norm() const;

    friend Vector operator*(const double& scalar, const Vector& vector);

    friend Vector operator/(const Vector& vector, const double& scalar);
};

std::ostream& operator<<(std::ostream &output_stream, const Vector& vector);

#endif
