#pragma once
#include <string>
#include <vector>
#include "pull.h"
class Set
{
  private:
    std::vector<Pull> pulls;
    void parse(std::string line);
  public:
    Set(std::string line);

};
