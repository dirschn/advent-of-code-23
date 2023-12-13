#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int parse_line(string line) {
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
  return (first * 10)  + last;
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
    int sum = 0;

    while(file){
      getline(file, line);
      sum += parse_line(line);
    }
    file.close();
    cout << sum;
  }
  return 0;
}
