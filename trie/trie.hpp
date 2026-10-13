
#include <string>


struct Trie {
    struct Node {
        Node(const char l) : letter(l) {};
        char letter = 0;
        bool isWord = false;
        Node* next[26] { nullptr }; 
    };
    
    Node* root = new Node('\0');
    bool exists(const std::string&);
    void insert(const std::string&);
    Node* starts_with(const std::string&);
};