#ifndef __OPTION_H
#define __OPTION_H

#include <stdexcept>

template <typename T>
class option {
private:
  bool _is_some;
  const T& value;

public:
  option(bool is_some, const T& value) :
    _is_some(is_some), value(value) {
  };

  bool is_some() const {
    return _is_some;
  };

  T get_value() const {
    if (_is_some) {
      return value;
    } else {
      throw (std::logic_error ("Trying to get value of an option equal to none."));
    }
  };
};

#endif
