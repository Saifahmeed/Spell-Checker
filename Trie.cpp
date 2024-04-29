#include "Trie.h"

Trie::Trie() : root(new Node()) {}

void Trie::insert(const string& wd) {
    Node* curNode = root;
    for (char c : wd) {
        int idx = tolower(c) - 'a';
        if (curNode->children[idx] == nullptr) {
            curNode->children[idx] = new Node();
        }
        curNode = curNode->children[idx];
    }
    curNode->end = true;
}

bool Trie::search(const string& wd) {
    Node* curNode = root;
    for (char c : wd) {
        int idx = c - 'a';
        if (curNode->children[idx] == nullptr) {
            return false;
        }
        curNode = curNode->children[idx];
    }
    return curNode != nullptr && curNode->end;
}

vector<string> Trie::suggest(const string& wd) {
    vector<string> suggestions;

    // Generate suggestions by changing each character
    for (int i = 0; i < wd.length(); ++i) {
        for (char c = 'a'; c <= 'z'; c++) {
            string modified = wd;
            modified[i] = c;
            if (search(modified)) {
                suggestions.push_back(modified);
            }
        }
    }

    // Generate suggestions by inserting each character
    for (int i = 0; i <= wd.length(); ++i) {
        for (char c = 'a'; c <= 'z'; c++) {
            string modified = wd;
            modified.insert(i, 1, c);
            if (search(modified)) {
                suggestions.push_back(modified);
            }
        }
    }

    // Generate suggestions by deleting each character
    for (int i = 0; i < wd.length(); ++i) {
        string modified = wd;
        modified.erase(i, 1);
        if (search(modified)) {
            suggestions.push_back(modified);
        }
    }

    // Generate suggestions by swapping adjacent characters
    for (int i = 0; i < wd.length() - 1; ++i) {
        string modified = wd;
        swap(modified[i], modified[i + 1]);
        if (search(modified)) {
            suggestions.push_back(modified);
        }
    }

    return suggestions;
}
