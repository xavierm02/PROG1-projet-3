#ifndef __OPTION_H
#define __OPTION_H

#include <stdexcept>
template <typename T>
class option {
private:
  bool is_defined;
  union {
    const T value;
    bool _;
  };

public:
  option(bool is_defined, const T& value) :
    is_defined(is_defined), value(value) {
  };

  bool get_is_defined() const {
    return is_defined;
  };

  T get_value() const {
    if (is_defined) {
      return value;
    } else {
      throw (std::logic_error ("Trying to get value of an option equal to none."));
    }
  };
};

#endif
