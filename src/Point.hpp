#include "Vector.hpp"

class Point {
  protected:
    double x;
    double y;
    double z;
  public:
    Point();

    Point(double x, double y, double z);

    double get_x() const;
    double get_y() const;
    double get_z() const;

    Point operator+(const Vector& vector) const;

    Point operator-(const Vector& vector) const;

    Vector operator-(const Point& point) const;
};

std::ostream& operator<<(std::ostream &output_stream, const Point& vector);
