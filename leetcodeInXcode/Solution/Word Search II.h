//
//  Word Search II.h
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
    
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // init lookup dict
        Trie trie;
        for (string word : words) {
            trie.insert(word);
        }
        
        // search the dict and board
        int n = (int)board.size();
        if (n <= 0) return vector<string>();
        int m = (int)board[0].size();
        if (m <= 0) return vector<string>();
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        string path;
        unordered_set<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                recursiveFindWords(board, visit, result, i, j, trie.root, path);
            }
        }
        
        return vector<string>(result.begin(), result.end());
    }
    
private:
    void recursiveFindWords(vector<vector<char>> &board, vector<vector<bool>> &visit, unordered_set<string> &result, int i, int j, TrieNode *node, string &path) {
        
        if (i < 0 || i >= board.size()) return;
        if (j < 0 || j >= board[i].size()) return;
        if (visit[i][j]) return;
        
        visit[i][j] = true;
        path.push_back(board[i][j]);
        int index = board[i][j] - 'a';
        if (node->children[index]) {
            node = node->children[index];
            if (node->isLeaf) result.insert(path);
            recursiveFindWords(board, visit, result, i - 1, j, node, path);
            recursiveFindWords(board, visit, result, i + 1, j, node, path);
            recursiveFindWords(board, visit, result, i, j - 1, node, path);
            recursiveFindWords(board, visit, result, i, j + 1, node, path);
        }
        visit[i][j] = false;
        path.pop_back();
    }
};