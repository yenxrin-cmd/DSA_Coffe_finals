#include "Searching.h"
#include "Utils.h"
using namespace std;

vector<Product> linearKeywordSearch(const vector<Product>& all, const string& keyword,
                                    int& comparisons) {
    vector<Product> found;
    string key = toLower(keyword);
    comparisons = 0;
    for (const Product& p : all) {
        ++comparisons;
        if (toLower(p.name).find(key) != string::npos ||
            toLower(p.brand).find(key) != string::npos ||
            toLower(p.category).find(key) != string::npos)
            found.push_back(p);
    }
    return found;
}

int lowerBoundPrice(const vector<Product>& v, double value, int& steps) {
    int lo = 0, hi = static_cast<int>(v.size());
    while (lo < hi) {
        ++steps;
        int mid = lo + (hi - lo) / 2;
        if (v[mid].price < value) lo = mid + 1; else hi = mid;
    }
    return lo;
}

int upperBoundPrice(const vector<Product>& v, double value, int& steps) {
    int lo = 0, hi = static_cast<int>(v.size());
    while (lo < hi) {
        ++steps;
        int mid = lo + (hi - lo) / 2;
        if (v[mid].price <= value) lo = mid + 1; else hi = mid;
    }
    return lo;
}
