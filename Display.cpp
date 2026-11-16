#include "Display.h"
#include <iomanip>
#include <iostream>
#include "Utils.h"
using namespace std;

void printHeader() {
    cout << left << setw(5) << "ID" << setw(30) << "PRODUCT" << setw(16) << "CATEGORY"
         << setw(12) << "BRAND" << right << setw(10) << "PRICE" << setw(8) << "STOCK" << '\n'
         << string(81, '-') << '\n';
}

void printProduct(const Product& p) {
    cout << left << setw(5) << p.id << setw(30) << fit(p.name, 29)
         << setw(16) << fit(p.category, 15) << setw(12) << fit(p.brand, 11)
         << right << setw(10) << fixed << setprecision(2) << p.price
         << setw(8) << p.stockQuantity << '\n';
}

void printTable(const vector<Product>& list) {
    printHeader();
    for (const Product& p : list) printProduct(p);
    cout << string(81, '-') << '\n' << list.size() << " item(s)\n";
}
