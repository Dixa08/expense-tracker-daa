#include <unordered_map>
#include <string>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    int expenseIdx = -1;
};

class ExpenseTrie {
    TrieNode* root = new TrieNode();
public:
    void insert(std::string s, int idx) {
        TrieNode* curr = root;
        for (char c : s) {
            if (!curr->children[c]) curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->expenseIdx = idx;
    }
    int search(std::string s) {
        TrieNode* curr = root;
        for (char c : s) {
            if (!curr->children[c]) return -1;
            curr = curr->children[c];
        }
        return curr->expenseIdx;
    }
};