//
//  Implement Trie (Prefix Tree).h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/19/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class TrieNode {
public:
    const static int ALPHABET = 26;
    bool isLeaf;
    TrieNode *children[ALPHABET];
    // Initialize your data structure here.
    TrieNode() : isLeaf(false) {
        fill_n(children, ALPHABET, nullptr);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *node = root;
        for (char c : s) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isLeaf = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *node = root;
        for (char c : key) {
            int index = c - 'a';
            if (!node || !node->children[index]) return false;
            node = node->children[index];
        }
        return node && node->isLeaf;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node || !node->children[index]) return false;
            node = node->children[index];
        }
        return node;
    }
    
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");