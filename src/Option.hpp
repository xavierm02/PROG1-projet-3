#ifndef __OPTION_H
#define __OPTION_H

#include <stdexcept>
template <typename T>
class Option {/*
private:
  bool is_defined;
  union {
    T value;
    bool _;
  };

public:
  Option(const T& value) :
    is_defined(true), value(value) {
  };

  Option() :
    is_defined(false) {
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
  };*/
};

#endif
