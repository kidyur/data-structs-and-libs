
#include "segtree.hpp"

void Segtree::fillTree_(Node* node, int diap) {
    if (diap == 1) return;
    node->left = new Node(0);
    node->right = new Node(0);
    fillTree_(node->left, diap >> 1);
    fillTree_(node->right, diap >> 1);
}

// returns the val of the node provided
int Segtree::update_(const int i, const int val, const int l_tree, const int r_tree, Segtree::Node* node) 
{
    if (l_tree == r_tree) {
        values_[i] = val;
        node->val = val;
        return node->val;
    }

    int m = (l_tree + r_tree) / 2;
    if (i <= m) {
        node->val = node->right->val + update_(i, val, l_tree, m, node->left);
    } else {
        node->val = node->left->val + update_(i, val, m+1, r_tree, node->right);
    }
    return node->val;
}

void Segtree::update(const int i, const int val) 
{
    update_(i, val, 0, size()-1, root_); 
}

int Segtree::range(const int l, const int r) {
    return range_(l, r, 0, size()-1, root_);
}

int Segtree::range_(int l, int r, int l_tree, int r_tree, Node* node) 
{
    if (r < l_tree || l > r_tree)
        return 0;
    if (l <= l_tree && r_tree <= r)
        return node->val;
    int m = (l_tree + r_tree) / 2;
    return range_(l, r, l_tree, m, node->left)
         + range_(l, r, m + 1, r_tree, node->right);
}