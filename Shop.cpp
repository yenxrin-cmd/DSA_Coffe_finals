#include "Shop.h"
using namespace std;

Shop::Shop() : catalog(4) {}

void Shop::addSeed(const string& name, const string& cat, const string& brand,
                   double price, int stock) {
    catalog.add(Product{nextProductId++, name, cat, brand, price, stock});
}

Product* Shop::findById(int id) {
    int steps;
    int idx = index.find(id, steps);
    return idx < 0 ? nullptr : &catalog.at(idx);
}

void seedCatalog(Shop& s) {
    s.addSeed("Classic Instant Coffee 100g",   "Instant Coffee", "Nescafe",  185.00, 40);
    s.addSeed("Gold Blend Jar 100g",           "Instant Coffee", "Nescafe",  265.00, 25);
    s.addSeed("3-in-1 Original Sachet 30s",    "Instant Coffee", "Nescafe",  168.00, 60);
    s.addSeed("Qualita Oro Beans 1kg",         "Coffee Beans",   "Lavazza", 1250.00, 12);
    s.addSeed("Crema e Gusto Ground 250g",     "Ground Coffee",  "Lavazza",  420.00, 18);
    s.addSeed("A Modo Mio Capsules 16s",       "Capsules",       "Lavazza",  595.00, 20);
    s.addSeed("Classico Whole Beans 250g",     "Coffee Beans",   "Illy",     980.00,  9);
    s.addSeed("Intenso Ground Tin 250g",       "Ground Coffee",  "Illy",     915.00, 14);
    s.addSeed("Iperespresso Capsules 18s",     "Capsules",       "Illy",     865.00, 11);
    s.addSeed("Brown Coffee 3-in-1 30s",       "Instant Coffee", "Kopiko",   145.00, 80);
    s.addSeed("Black 3-in-1 Sachet 30s",       "Instant Coffee", "Kopiko",   139.00, 70);
    s.addSeed("Cappuccino Cup Drink 240ml",    "Ready-to-Drink", "Kopiko",    42.00, 96);
    s.addSeed("Caramel Macchiato Can 180ml",   "Ready-to-Drink", "Nescafe",   55.00, 48);
    s.addSeed("Espresso Roast Beans 450g",     "Coffee Beans",   "Illy",    1490.00,  6);
    s.index.rebuild(s.catalog);
}
