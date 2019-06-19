#include <vector>
#include <string>
#include <iostream>

namespace string_utils {

using std::string;
using std::vector;

/*
 * recursive function to parse delim separated strings
 */
static const string HAS_CYCLE_MESSAGE = "Invalid input: Network has a cycle!";

static void split_string(
    const string& s, const char delim, vector<string>& results) {
  size_t start = 0;
  for (size_t i = 0; i < s.length(); i++) {
    if (s.at(i) == delim && start < s.length()) {
      results.push_back(s.substr(start, i - start));
      start = i + 1;
    }
  }
  if (start < s.length()) {
    results.push_back(s.substr(start));
  }
}

}  // endnamespace string_utils
