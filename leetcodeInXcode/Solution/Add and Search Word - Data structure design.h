//
//  Add and Search Word - Data structure design.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/19/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class WordDictionary {
public:
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
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isLeaf = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string key) {
        return recursiveSearch(key, 0, root);
    }
    
private:
    TrieNode* root;
    
    bool recursiveSearch(string key, int k, TrieNode *node) {
        for (; k < key.size(); k++) {
            if (key[k] == '.') {
                for (int i = 0; i < TrieNode::ALPHABET; i++) {
                    if (node->children[i] && recursiveSearch(key, k+1, node->children[i])) {
                        return true;
                    }
                }
                return false;
            }
            int index = key[k] - 'a';
            if (!node || !node->children[index]) return false;
            node = node->children[index];
        }
        return node && node->isLeaf;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");