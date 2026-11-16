#include "Cart.h"

Cart::Cart() : head(nullptr), tail(nullptr), cur(nullptr), count(0) {}

Cart::~Cart() { clear(); }

void Cart::add(int productId, int quantity) {
    for (CartNode* n = head; n != nullptr; n = n->next) {
        if (n->productId == productId) { n->quantity += quantity; return; }
    }
    CartNode* node = new CartNode(productId, quantity);
    if (tail == nullptr) head = tail = node;
    else { tail->next = node; node->prev = tail; tail = node; }
    if (cur == nullptr) cur = node;
    ++count;
}

bool Cart::moveNext() {
    if (cur && cur->next) { cur = cur->next; return true; }
    return false;
}

bool Cart::movePrev() {
    if (cur && cur->prev) { cur = cur->prev; return true; }
    return false;
}

void Cart::removeCurrent() {
    if (cur == nullptr) return;
    CartNode* doomed = cur;
    if (doomed->prev) doomed->prev->next = doomed->next; else head = doomed->next;
    if (doomed->next) doomed->next->prev = doomed->prev; else tail = doomed->prev;
    cur = doomed->next ? doomed->next : doomed->prev;
    delete doomed;
    --count;
}

void Cart::clear() {
    while (head != nullptr) {
        CartNode* next = head->next;
        delete head;
        head = next;
    }
    tail = cur = nullptr;
    count = 0;
}
