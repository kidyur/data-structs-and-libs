
#include <vector>


class Segtree {
public:
    Segtree(const int size) {
        int vecSize = 1;
        while (vecSize < size)  
            vecSize *= 2;
        values_.resize(vecSize);
        root_ = new Node(0);
        fillTree_(root_, vecSize);
    }    

    struct Node {
        Node(const int v) : val(v) {};
        Node* left = nullptr;
        Node* right = nullptr;
        int val = 0;
    };

    const int operator[](const int i) { return values_[i]; }
    int size() { return values_.size(); };
    void update(const int i, const int val);
    int range(const int l, const int r);
private:
    void fillTree_(Node* root, int diap);
    int update_(const int i, const int val, const int l_tree, const int r_tree, Segtree::Node* node);
    int range_(int l, int r, int l_tree, int r_tree, Node* node);
    std::vector<int> values_;
    Node* root_ = nullptr;
};

// Segtree sg = Segtree(size);