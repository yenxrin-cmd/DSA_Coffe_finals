#pragma once
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include "Cart.h"
#include "Catalog.h"
#include "IdIndex.h"
#include "Product.h"


struct OrderLine { int productId; int quantity; };

struct Order {
    int orderId;
    std::string customer;
    std::vector<OrderLine> lines;
};


struct AdminAction {
    enum Type { ADD_PRODUCT, RESTOCK } type;
    Product product;  
    int productId;    
    int amount;       
};


struct Shop {
    Catalog catalog;
    IdIndex index;
    Cart cart;
    std::queue<Order> orders;
    std::stack<AdminAction> undoStack;
    std::stack<AdminAction> redoStack;
    int nextProductId = 1;
    int nextOrderId = 1001;

    Shop();

    void addSeed(const std::string& name, const std::string& cat, const std::string& brand,
                 double price, int stock);
    Product* findById(int id);  
};

void seedCatalog(Shop& s);  
