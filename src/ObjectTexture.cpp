#include "ObjectTexture.hpp"

std::shared_ptr<ObjectTexture> ObjectTexture::wrap() const {
  return std::shared_ptr<ObjectTexture>(this->clone());
}
