#pragma once
#include <vector>
#include "Product.h"


class Catalog {
private:
    Product* items;
    int count;
    int capacity;

    void grow();

public:
    explicit Catalog(int initialCapacity = 4);
    ~Catalog();
    Catalog(const Catalog&) = delete;
    Catalog& operator=(const Catalog&) = delete;

    void add(const Product& p);
    bool removeById(int id);

    int size() const { return count; }
    Product& at(int i) { return items[i]; }
    const Product& at(int i) const { return items[i]; }

    std::vector<Product> toVector() const;
};
