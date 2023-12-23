#pragma once
#include <string>

class Pull
{
  private:
    int count;
    std::string color;
    void parse(std::string line);
  public:
      Pull(std::string pull);
      int get_count();
      std::string get_color();
};
