#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "split.h"

using namespace std;

int part_one(string line) {
  vector<string> split_line;

  split(line, " ", split_line);

}

int main(int argc, char *argv[]) {
  string filename;
  if (argc == 1){
    filename = "input.txt";
  } else {
    filename = argv[1];
  }

  fstream file;
  file.open(filename);

  if (file.is_open()) {
    string line;
    int p_one_sum = 0;

    while(file) {
      getline(file, line);

      p_one_sum += part_one(line);
    }
  }

}
