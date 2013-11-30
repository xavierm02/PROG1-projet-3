#ifndef __OPTION_H
#define __OPTION_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Option {
private:
  bool defined;
  const T value;
public:
  Option(): defined(false), value(0) {}

  Option(const T& value): defined(true), value(value) {}

  Option(const bool defined, const T& value): defined(defined), value(value) {}

  bool is_defined() const {
    return defined;
  }

  T get_value() const {
    if (defined) return value;
    else throw (std::logic_error("Trying to get the value of an undefined option."));
  }
};

template <typename T>
std::ostream& operator<<(std::ostream &output_stream, const Option<T>& option) {
  if (option.is_defined()) {
    return output_stream << "Some(" << option.get_value() << ")";
  } else {
    return output_stream << "None";
  }
}

#endif
