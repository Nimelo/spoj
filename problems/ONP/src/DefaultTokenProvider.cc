#include "DefaultTokenProvider.hpp"
#include <string>

namespace spoj::tokens {
  DefaultTokenProvider::DefaultTokenProvider(const std::string & line)
    : content_{line}, position_{0} {}

  DefaultTokenProvider::DefaultTokenProvider(const char* line)
    : DefaultTokenProvider(std::string(line)) {}


  std::string DefaultTokenProvider::getNext() {
    return content_.substr(position_++, 1);
  }

  bool DefaultTokenProvider::hasNext() const {
    return position_ < content_.size();
  }
}