#include "Point.hpp"
#include <memory>
#include "Object.hpp"

class ObjectPoint: public Point {
  private:
    std::shared_ptr<Object> object;
  public:
    ObjectPoint(std::shared_ptr<Object> object, const Point& point);

    std::shared_ptr<Object> get_object() const;
};
