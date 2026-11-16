#pragma once
#include <string>
#include "Product.h"


struct BrandNode {
    std::string brand;
    int productCount;
    std::string featured;
    BrandNode* next;
    BrandNode(const std::string& b, const std::string& f)
        : brand(b), productCount(1), featured(f), next(nullptr) {}
};

class BrandShowcase {
private:
    BrandNode* tail;  

public:
    BrandShowcase();
    ~BrandShowcase();
    BrandShowcase(const BrandShowcase&) = delete;
    BrandShowcase& operator=(const BrandShowcase&) = delete;

    void addProduct(const Product& p);
    BrandNode* head() const { return tail ? tail->next : nullptr; }
};
