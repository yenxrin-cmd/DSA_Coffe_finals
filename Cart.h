#pragma once


struct CartNode {
    int productId;
    int quantity;
    CartNode* prev;
    CartNode* next;
    CartNode(int id, int q) : productId(id), quantity(q), prev(nullptr), next(nullptr) {}
};

class Cart {
private:
    CartNode* head;
    CartNode* tail;
    CartNode* cur;
    int count;

public:
    Cart();
    ~Cart();
    Cart(const Cart&) = delete;
    Cart& operator=(const Cart&) = delete;

    void add(int productId, int quantity);
    void removeCurrent();
    void clear();

    bool moveNext();
    bool movePrev();

    bool empty() const { return head == nullptr; }
    int size() const { return count; }
    CartNode* current() const { return cur; }
    CartNode* first() const { return head; }
};
