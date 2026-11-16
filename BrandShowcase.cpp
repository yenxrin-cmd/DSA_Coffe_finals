#include "BrandShowcase.h"
#include "Utils.h"
using namespace std;

BrandShowcase::BrandShowcase() : tail(nullptr) {}

BrandShowcase::~BrandShowcase() {
    if (tail == nullptr) return;
    BrandNode* node = tail->next;
    tail->next = nullptr;  
    while (node != nullptr) {
        BrandNode* next = node->next;
        delete node;
        node = next;
    }
}

void BrandShowcase::addProduct(const Product& p) {
    if (tail != nullptr) {
        BrandNode* n = tail;
        do {
            if (toLower(n->brand) == toLower(p.brand)) { ++n->productCount; return; }
            n = n->next;
        } while (n != tail);
    }
    BrandNode* node = new BrandNode(p.brand, p.name);
    if (tail == nullptr) { node->next = node; tail = node; }
    else { node->next = tail->next; tail->next = node; tail = node; }
}
