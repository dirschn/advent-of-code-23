#include <string>
#include <vector>

using namespace std;

void split(const string& str, const string& delim, vector<string>& parts)
{
  size_t start = 0;
  size_t end = str.find(delim);

  while (end != string::npos) {
    parts.push_back(str.substr(start, end - start));
    start = end + delim.length();
    end = str.find(delim, start);
  }

  // Add the last part (or the whole string if no delimiter was found)
  parts.push_back(str.substr(start));
}
