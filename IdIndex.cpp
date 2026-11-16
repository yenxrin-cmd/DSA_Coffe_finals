#include "IdIndex.h"
#include <algorithm>
using namespace std;

IdIndex::IdIndex() : root(nullptr) {}

IdIndex::~IdIndex() { destroy(root); }

BSTNode* IdIndex::insert(BSTNode* node, int id, int index) {
    if (node == nullptr) return new BSTNode(id, index);
    if (id < node->id) node->left = insert(node->left, id, index);
    else if (id > node->id) node->right = insert(node->right, id, index);
    return node;
}

void IdIndex::destroy(BSTNode* node) {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}


void IdIndex::buildBalanced(vector<pair<int, int>>& sorted, int lo, int hi) {
    if (lo > hi) return;
    int mid = (lo + hi) / 2;
    root = insert(root, sorted[mid].first, sorted[mid].second);
    buildBalanced(sorted, lo, mid - 1);
    buildBalanced(sorted, mid + 1, hi);
}

void IdIndex::rebuild(const Catalog& c) {
    destroy(root);
    root = nullptr;
    vector<pair<int, int>> sorted;
    for (int i = 0; i < c.size(); ++i) sorted.push_back({c.at(i).id, i});
    sort(sorted.begin(), sorted.end());
    buildBalanced(sorted, 0, static_cast<int>(sorted.size()) - 1);
}

int IdIndex::find(int id, int& steps) const {
    steps = 0;
    BSTNode* cur = root;
    while (cur != nullptr) {
        ++steps;
        if (id == cur->id) return cur->index;
        cur = (id < cur->id) ? cur->left : cur->right;
    }
    return -1;
}
