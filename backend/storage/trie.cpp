// ============================================================
// Member 4 — Trie: autocomplete for expense descriptions
// DAA Concept  : Tree Data Structure (Prefix Tree)
// Time          : O(m) insert/search  where m = word length
// Space         : O(ALPHABET * m * n)
// Compile       : g++ -std=c++17 trie.cpp -o trie
// Run           : ./trie
// ============================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define ALPHA 26

struct TrieNode {
    TrieNode* ch[ALPHA];
    bool      isEnd;
    float     lastAmount;
    string    fullWord;

    TrieNode() {
        for (int i = 0; i < ALPHA; i++) ch[i] = nullptr;
        isEnd = false; lastAmount = 0;
    }
};

class Trie {
    TrieNode* root;

    void collect(TrieNode* node, vector<pair<string,float>>& res, int limit) {
        if ((int)res.size() >= limit) return;
        if (node->isEnd) res.push_back({node->fullWord, node->lastAmount});
        for (int i = 0; i < ALPHA; i++)
            if (node->ch[i]) collect(node->ch[i], res, limit);
    }

public:
    Trie() { root = new TrieNode(); }

    void insert(const string& word, float amount = 0) {
        TrieNode* cur = root;
        for (char c : word) {
            int idx = tolower(c) - 'a';
            if (idx < 0 || idx >= ALPHA) continue;
            if (!cur->ch[idx]) cur->ch[idx] = new TrieNode();
            cur = cur->ch[idx];
        }
        cur->isEnd = true;
        cur->lastAmount = amount;
        cur->fullWord = word;
    }

    // Returns up to 'limit' suggestions for prefix
    vector<pair<string,float>> autocomplete(const string& prefix, int limit = 5) {
        TrieNode* cur = root;
        for (char c : prefix) {
            int idx = tolower(c) - 'a';
            if (idx < 0 || idx >= ALPHA || !cur->ch[idx]) return {};
            cur = cur->ch[idx];
        }
        vector<pair<string,float>> res;
        collect(cur, res, limit);
        return res;
    }
};

int main() {
    Trie trie;

    // Insert past expense descriptions with their usual amounts
    trie.insert("Pizza",         150);
    trie.insert("Petrol",        500);
    trie.insert("Protein shake", 299);
    trie.insert("Groceries",     320);
    trie.insert("Google Play",    99);
    trie.insert("Gym fees",      600);
    trie.insert("Auto rickshaw",  45);
    trie.insert("Amazon order",  799);

    cout << "=== TRIE AUTOCOMPLETE ===" << endl;

    vector<string> queries = {"p", "g", "a", "gr", "au"};
    for (auto& q : queries) {
        auto suggestions = trie.autocomplete(q);
        cout << "Type \"" << q << "\" -> ";
        if (suggestions.empty()) {
            cout << "(no suggestions)";
        } else {
           for (int i = 0; i < suggestions.size(); i++)
    cout << "[" << suggestions[i].first << " Rs." << suggestions[i].second << "] ";
        }
        cout << endl;
    }

    return 0;
}
