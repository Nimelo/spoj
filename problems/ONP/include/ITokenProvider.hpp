#pragma once

#include <string>

namespace spoj::tokens {
  class ITokenProvider {
  public:
    virtual std::string getNext() = 0;
    virtual bool hasNext() const = 0;
  };
}