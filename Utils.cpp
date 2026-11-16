#include "Utils.h"
#include <cctype>
using namespace std;

string toLower(string s) {
    for (char& c : s) c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    return s;
}

string fit(const string& s, size_t width) {
    return s.size() <= width ? s : s.substr(0, width - 1) + ".";
}
