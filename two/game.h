#pragma once
#include <string>
#include "set.h"

class Game
{
  private:
    int id;
    Set sets[];
    
    void parse(std::string line);
  public:
    Game(std::string line);
    int get_id();


};
