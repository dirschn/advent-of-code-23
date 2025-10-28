#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "split.h"

using namespace std;

// input line:
// Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
// id: 1 (left of colon, after space)
// set: (rest of line, split by ";")
// number, color (split by ",")

int part_one(vector<string> &lines) {
  unsigned int sum = 0;
  bool pass = true;
  string id_delim = ": ";
  string set_delim = "; ";
  string color_delim = ", ";

  const int RED_MAX = 12;
  const int GREEN_MAX = 13;
  const int BLUE_MAX = 14;

  unsigned int game_id = 1;
  for (const string &line : lines) {
    // Split the game line
    vector<string> split_line;
    split(line, id_delim, split_line);

    // grab the sets from the split line
    string sets = split_line[1];

    // split the sets into pulls
    vector<string> split_sets;
    split(sets, set_delim, split_sets);

    for (const string &set : split_sets) {
      // split the pulls into color/count
      vector<string> pulls;
      split(set, color_delim, pulls);
      for (const string &pull : pulls) {
        vector<string> pull_parts;
        split(pull, " ", pull_parts);
        int count = stoi(pull_parts[0]);
        string color = pull_parts[1];

        if ((color == "red" && count > RED_MAX) || (color == "green" && count > GREEN_MAX) || (color == "blue" && count > BLUE_MAX))
        {
          // if any pull exceeds max, fail the game
          pass = false;
        }
      }
    }
    if (pass)
    {
      sum += game_id;
    }
    game_id++;
    pass = true;
  }
  return sum;
}

int part_two(vector<string> &lines) {
  int result = 0;

  return result;
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
    vector<string> lines;

    while (getline(file, line)) {
      lines.push_back(line);
    }

    file.close();

    int p_one_sum = part_one(lines);
    int p_two_sum = part_two(lines);

    cout << "Part 1 sum: " << p_one_sum << endl;
    cout << "Part 2 sum: " << p_two_sum << endl;

  } else {
    cerr << "Failed to open file: " << filename << endl;
    return 1;
  }

  return 0;
}
