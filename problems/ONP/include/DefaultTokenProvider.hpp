#pragma once

#include "ITokenProvider.hpp"
#include <string>
#include <cstddef>

namespace spoj::tokens {
  class DefaultTokenProvider : public ITokenProvider {
  public:
    DefaultTokenProvider(const std::string & line);
    DefaultTokenProvider(const char* line);

    virtual std::string getNext();
    virtual bool hasNext() const;
  private:
    std::string content_;
    std::size_t position_;
  };
}