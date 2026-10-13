#include "trie.hpp"
#include <cassert>


void insert_test() 
{
    Trie trie = Trie();
    trie.insert("bar");
    trie.insert("foo");
    trie.insert("fan");

    assert(trie.exists("bar"));
    assert(trie.exists("foo"));
    assert(trie.exists("fan"));
    assert(trie.exists("nonexistingword") == false);

    assert(trie.starts_with("nonexistingprefix") == nullptr);
    assert(trie.starts_with("b"));
    assert(trie.starts_with("f"));
    assert(trie.starts_with("foo"));
}


int main() 
{
    insert_test();
}