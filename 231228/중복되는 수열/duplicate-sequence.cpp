#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[10];
    bool is_end;

    TrieNode() {
        is_end = false;
        for (int i = 0; i < 10; i++) {
            children[i] = nullptr;
        }
    }
};

TrieNode* root = new TrieNode();

bool insertWord(string s) {
    TrieNode* t = root;
    for (char ch : s) {
        int index = ch - '0';
        if (t->children[index] == nullptr) {
            t->children[index] = new TrieNode();
        }
        t = t->children[index];
        if (t->is_end) return false;
    }
    t->is_end = true;
    return true;
}

int main() {
    int n;
    cin >> n;
    string temp;
    bool isPrefix = true;
    for (int i = 0; i < n && isPrefix; i++) {
        cin >> temp;
        isPrefix = insertWord(temp);
    }
    cout << (isPrefix ? 1 : 0) << endl;
    return 0;
}