#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include "BrandShowcase.h"
#include "Display.h"
#include "Input.h"
#include "Menus.h"
#include "Searching.h"
#include "Sorting.h"
using namespace std;


void viewCatalog(Shop& s) {
    cout << "\n--- COMPLETE CATALOG ---\n";
    printTable(s.catalog.toVector());
}


void filterByBrand(Shop& s) {
    vector<Product> all = s.catalog.toVector();
    vector<string> brands;
    for (const Product& p : all)
        if (find(brands.begin(), brands.end(), p.brand) == brands.end()) brands.push_back(p.brand);

    cout << "\nOfficial partner brands:\n";
    for (size_t i = 0; i < brands.size(); ++i) cout << "  " << i + 1 << ". " << brands[i] << '\n';
    int choice = readInt("Choose a brand number (0 to cancel): ", 0, static_cast<int>(brands.size()));
    if (choice == 0) return;

    vector<Product> result;
    for (const Product& p : all)
        if (p.brand == brands[choice - 1]) result.push_back(p);
    cout << "\n--- " << brands[choice - 1] << " PRODUCTS ---\n";
    printTable(result);
}


void searchProducts(Shop& s) {
    cout << "\n  1. Keyword search (Linear Search)\n  2. Product ID search (Binary Search Tree)\n";
    int mode = readInt("Choose search type: ", 1, 2);

    if (mode == 1) {
        string key = readLine("Enter keyword (name, brand or category): ");
        if (key.empty()) { cout << "  [!] Keyword cannot be empty.\n"; return; }
        int comparisons = 0;
        vector<Product> found = linearKeywordSearch(s.catalog.toVector(), key, comparisons);
        cout << "\n--- RESULTS FOR \"" << key << "\" ---\n";
        if (found.empty()) cout << "No matching products.\n"; else printTable(found);
        cout << "(Linear search made " << comparisons << " comparisons)\n";
    } else {
        int id = readInt("Enter product ID: ", 1, 1000000);
        int steps = 0;
        int idx = s.index.find(id, steps);
        if (idx < 0) cout << "\n[!] Product not found. (BST visited " << steps << " node(s))\n";
        else {
            cout << '\n';
            printHeader();
            printProduct(s.catalog.at(idx));
            cout << "(BST visited " << steps << " node(s))\n";
        }
    }
}


void filterByPrice(Shop& s) {
    double lo = readPrice("Minimum price (PHP): ");
    double hi = readPrice("Maximum price (PHP): ");
    if (lo > hi) swap(lo, hi);

    vector<Product> v = s.catalog.toVector();
    if (v.empty()) { cout << "Catalog is empty.\n"; return; }
    quickSort(v, 0, static_cast<int>(v.size()) - 1, byPrice);  
    int steps = 0;
    int first = lowerBoundPrice(v, lo, steps);
    int last = upperBoundPrice(v, hi, steps);

    cout << fixed << setprecision(2) << "\n--- PRODUCTS FROM PHP " << lo << " TO PHP " << hi << " ---\n";
    if (first >= last) cout << "No products in that price range.\n";
    else printTable(vector<Product>(v.begin() + first, v.begin() + last));
    cout << "(Binary search used " << steps << " steps on the price-sorted list)\n";
}

// Menu 8
void brandShowcaseMenu(Shop& s) {
    BrandShowcase showcase;
    for (int i = 0; i < s.catalog.size(); ++i) showcase.addProduct(s.catalog.at(i));
    BrandNode* cur = showcase.head();
    if (cur == nullptr) { cout << "\nNo brands to show.\n"; return; }

    cout << "\n--- PARTNER BRAND SHOWCASE (circular list) ---\n"
         << "Press Enter for the next banner, or type q to leave.\n";
    while (true) {
        cout << "\n  ***************************************\n"
             << "   OFFICIAL PARTNER: " << cur->brand << '\n'
             << "   " << cur->productCount << " product(s) available - e.g. " << cur->featured << '\n'
             << "  ***************************************\n";
        string in = readLine("");
        if (!in.empty() && tolower(static_cast<unsigned char>(in[0])) == 'q') break;
        cur = cur->next;  
    }
}

// Menu 9
void sortInventory(Shop& s) {
    cout << "\n  1. Price (Quick Sort)\n  2. Stock (Quick Sort)\n  3. Brand (Insertion Sort)\n";
    int c = readInt("Sort by: ", 1, 3);
    vector<Product> v = s.catalog.toVector();
    if (v.empty()) { cout << "Catalog is empty.\n"; return; }
    int last = static_cast<int>(v.size()) - 1;

    if (c == 1) { quickSort(v, 0, last, byPrice); cout << "\n--- SORTED BY PRICE (low to high) ---\n"; }
    else if (c == 2) { quickSort(v, 0, last, byStock); cout << "\n--- SORTED BY STOCK (low to high) ---\n"; }
    else { insertionSort(v, byBrand); cout << "\n--- SORTED BY BRAND (A-Z) ---\n"; }
    printTable(v);
}
