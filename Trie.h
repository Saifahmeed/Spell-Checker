#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>
using namespace std;

class Trie {
private:
    struct Node {
        bool end;
        vector<Node*> children;

        Node() : end(false), children(26, nullptr) {}
    };

    Node* root;

public:
    Trie();
    void insert(const string& wd);
    bool search(const string& wd);
    vector<string> suggest(const string& wd);
};

#endif // TRIE_H
