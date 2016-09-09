class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : arr(vector<TrieNode*>(26, nullptr)), exist(false) {
        
    }
    vector<TrieNode*> arr;
    bool exist;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        auto cur = root;
        for(auto iter = word.begin(); iter != word.end(); cur = (cur->arr)[*iter-'a'], iter++) {
            if((cur->arr)[*iter-'a'] != nullptr) {
                continue;
            }
            (cur->arr)[*iter-'a'] = new TrieNode;
        }
        cur->exist = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto cur = root;
        auto iter = word.begin();
        while (iter != word.end() && (cur->arr)[*iter-'a'] != nullptr) {
            cur = (cur->arr)[*iter-'a'];
            iter++;
        }
        return iter == word.end() && cur->exist;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto cur = root;
        auto iter = prefix.begin();
        while (iter != prefix.end() && (cur->arr)[*iter-'a'] != nullptr) {
            cur = (cur->arr)[*iter-'a'];
            iter++;
        }
        return iter == prefix.end();
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");