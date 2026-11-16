#include "Sorting.h"
#include "Utils.h"
using namespace std;

bool byPrice(const Product& a, const Product& b) { return a.price < b.price; }
bool byStock(const Product& a, const Product& b) { return a.stockQuantity < b.stockQuantity; }
bool byBrand(const Product& a, const Product& b) {
    string x = toLower(a.brand), y = toLower(b.brand);
    return x != y ? x < y : a.name < b.name;
}
