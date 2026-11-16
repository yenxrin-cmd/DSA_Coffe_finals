#pragma once
#include <utility>
#include <vector>
#include "Catalog.h"


struct BSTNode {
    int id;
    int index;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int i, int idx) : id(i), index(idx), left(nullptr), right(nullptr) {}
};

class IdIndex {
private:
    BSTNode* root;

    static BSTNode* insert(BSTNode* node, int id, int index);
    static void destroy(BSTNode* node);
    void buildBalanced(std::vector<std::pair<int, int>>& sorted, int lo, int hi);

public:
    IdIndex();
    ~IdIndex();
    IdIndex(const IdIndex&) = delete;
    IdIndex& operator=(const IdIndex&) = delete;

    void rebuild(const Catalog& c);
    int find(int id, int& steps) const;  // returns catalog index, or -1
};
