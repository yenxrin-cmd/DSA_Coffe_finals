#include "Catalog.h"
#include <iostream>
using namespace std;

void Catalog::grow() {
    int newCapacity = capacity * 2;
    Product* bigger = new Product[newCapacity]();
    for (int i = 0; i < count; ++i) bigger[i] = items[i];
    delete[] items;
    items = bigger;
    capacity = newCapacity;
    cout << "  [Memory] Catalog resized to hold " << capacity << " products.\n";
}

Catalog::Catalog(int initialCapacity)
    : items(new Product[initialCapacity]()), count(0), capacity(initialCapacity) {}

Catalog::~Catalog() { delete[] items; }

void Catalog::add(const Product& p) {
    if (count == capacity) grow();
    items[count++] = p;
}

bool Catalog::removeById(int id) {
    for (int i = 0; i < count; ++i) {
        if (items[i].id == id) {
            for (int j = i; j + 1 < count; ++j) items[j] = items[j + 1];
            --count;
            return true;
        }
    }
    return false;
}

vector<Product> Catalog::toVector() const {
    return vector<Product>(items, items + count);
}
