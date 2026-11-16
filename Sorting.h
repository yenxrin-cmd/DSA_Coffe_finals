#pragma once
#include <utility>
#include <vector>
#include "Product.h"


template <typename Less>
void insertionSort(std::vector<Product>& v, Less less) {
    for (std::size_t i = 1; i < v.size(); ++i) {
        Product key = v[i];
        std::size_t j = i;
        while (j > 0 && less(key, v[j - 1])) { v[j] = v[j - 1]; --j; }
        v[j] = key;
    }
}

template <typename Less>
void quickSort(std::vector<Product>& v, int lo, int hi, Less less) {
    if (lo >= hi) return;
    Product pivot = v[lo + (hi - lo) / 2];
    int i = lo, j = hi;
    while (i <= j) {
        while (less(v[i], pivot)) ++i;
        while (less(pivot, v[j])) --j;
        if (i <= j) { std::swap(v[i], v[j]); ++i; --j; }
    }
    quickSort(v, lo, j, less);
    quickSort(v, i, hi, less);
}


bool byPrice(const Product& a, const Product& b);
bool byStock(const Product& a, const Product& b);
bool byBrand(const Product& a, const Product& b);
