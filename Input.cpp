#include "Input.h"
#include <iostream>
using namespace std;

string readLine(const string& prompt) {
    string line;
    cout << prompt;
    if (!getline(cin, line)) throw InputClosed();
    return line;
}

static bool readNumber(const string& prompt, double& out) {
    string s = readLine(prompt);
    try {
        size_t pos = 0;
        out = stod(s, &pos);
        return pos == s.size();
    } catch (...) {
        return false;
    }
}

int readInt(const string& prompt, int lo, int hi) {
    while (true) {
        double v;
        if (readNumber(prompt, v) && v == static_cast<int>(v) && v >= lo && v <= hi)
            return static_cast<int>(v);
        cout << "  [!] Please enter a whole number from " << lo << " to " << hi << ".\n";
    }
}

double readPrice(const string& prompt) {
    while (true) {
        double v;
        if (readNumber(prompt, v) && v >= 0) return v;
        cout << "  [!] Please enter a valid non-negative number.\n";
    }
}
