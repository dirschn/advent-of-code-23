#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int part_one(string line) {
  int first, last;

  for (int i = 0; i < line.length(); i++) {
    if(isdigit(line[i])){
      first = line[i] - '0';
      break;
    }
  }

  for (int i = line.length() - 1; i >= 0; i--) {
    if(isdigit(line[i])) {
      last = line[i] - '0';
      break;
    }
  }
  return (first * 10) + last;
}

int part_two(string line) {
  int first = 0;
  int last = 0;
  int first_index = 0;
  int last_index = 0;
  string numbers[9] = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
  };

  for (int i = 0; i < line.length(); i++) {
    if(isdigit(line[i])){
      first_index = i;
      first = line[i] - '0';
      break;
    }
  }

  if(first_index > 2) {
    int i = 1;
    for(string num : numbers) {
      int index = line.find(num);
      if(index < 0) { i++; continue; }
      else if(index < first_index) { first = i; first_index = index; }
      i++;
    }
  }

  for (int i = line.length() - 1; i >= 0; i--) {
    if(isdigit(line[i])) {
      last_index = i;
      last = line[i] - '0';
      break;
    }
  }

  if(last_index < line.length() - 2) {
    reverse(line.begin(), line.end());
    int i = 0;
    for(string num : numbers) {
      i++;
      reverse(num.begin(), num.end());
      int found = line.find(num);
      if(found < 0) { continue; }
      int index = line.length() - found;
      if(index > last_index) { last = i; last_index = index; }
    }
  }

  return (first * 10) + last;

}

int main(int argc, char *argv[]) {
  if(argc != 2){
    cout << "Usage: " << argv[0] << " <filename>";
    return 1;
  }

  fstream file;
  file.open(argv[1]);

  if(file.is_open()) {
    string line;
    int p_one_sum = 0;
    int p_two_sum = 0;

    while(file){
      getline(file, line);
      p_one_sum += part_one(line);
      p_two_sum += part_two(line);
    }
    file.close();
    cout << "Part one's answer is: " << p_one_sum << endl;
    cout << "Part two's answer is: " << p_two_sum << endl;
  }

  return 0;
}
