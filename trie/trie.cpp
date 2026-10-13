#include "trie.hpp"


bool Trie::exists(const std::string& word) 
{
    Node* node = starts_with(word);
    if (node == nullptr)
        return false;
    return node->isWord;
}


Trie::Node* Trie::starts_with(const std::string& prefix)
{
    Node* node = root;
    for (const char& let : prefix) {
        int letIdx = let - 'a';
        if (node->next[letIdx]) 
            node = node->next[letIdx];
        else 
            return nullptr;
    }
    return node;
}


void Trie::insert(const std::string& word)
{
    Node* node = root;
    for (const char& let : word) {
        int letIdx = let - 'a';
        if (node->next[letIdx] == nullptr) 
            node->next[letIdx] = new Node(let);
        node = node->next[letIdx];
    }
    node->isWord = true;
}