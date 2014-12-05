//
//  Word Ladder.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/3/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, char> visited;
        BiDirectBFS b1(dict, visited, 'a', start), b2(dict, visited, 'b', end);
        while (b1.hasNext() && b2.hasNext()) {
            if (b1.advanceLevel() || b2.advanceLevel()) {
                return b1.currentLevel() + b2.currentLevel() - 1;
            }
        }
        return 0;
    }
    
private:
    class BiDirectBFS {
    public:
        BiDirectBFS(unordered_set<string> &dict, unordered_map<string, char> &visited, char key, string first):
        visited(visited), key(key), dict(dict) {
            largeDict = (dict.size() * first.length() > 26 * first.length());
            q.push(first);
        }
        
        bool advanceLevel() {
            if (q.empty()) {
                return false;
            }
            level++;
            int cur_level_remain = int(q.size());
            while (cur_level_remain > 0) {
                // visit the front element
                cur_level_remain--;
                string s = q.front();
                q.pop();
                auto it = visited.find(s);
                // if unvisited
                if (it == visited.end()) {
                    visited[s] = key;
                    vector<string> neighbors = getNeighbors(s);
                    for (auto it = begin(neighbors); it != end(neighbors); it++) {
                        q.push(*it);
                    }
                } else if (it->second != key) {
                    // if has visited by the other queue
                    intersection = true;
                }
            }
            return intersection;
        }
        
        bool hasNext() {
            return !q.empty();
        }
        
        int currentLevel() {
            return level;
        }
        
    private:
        queue<string> q;
        int level = 0;
        char key;
        bool intersection = false;
        bool largeDict;
        unordered_map<string, char> &visited;
        unordered_set<string> &dict;
        
        vector<string> getNeighbors(string s) {
            vector<string> words;
            // use the faster method here
            if (largeDict) {
                // construct word and search
                for (int i = 0; i < s.length(); i++) {
                    string candidate = s;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (s[i] == c) {
                            continue;
                        }
                        candidate[i] = c;
                        if (dict.find(candidate) != dict.end()) {
                            auto it = visited.find(candidate);
                            if (it == visited.end() || it->second != key) {
                                words.push_back(candidate);
                            }
                        }
                    }
                }
            } else {
                // traverse dict and compare
                for (string word : dict) {
                    auto it = visited.find(word);
                    if (it == visited.end() || it->second != key) {
                        if (near(word, s)) {
                            words.push_back(word);
                        }
                    }
                }
            }
            return words;
        }
        
        static bool near(const string &a, const string &b) {
            if (a.length() != b.length()) {
                return false;
            }
            int diff = 0;
            for (int i = 0; i < a.length(); i++) {
                if (a[i] != b[i]) {
                    if (++diff > 1) {
                        return false;
                    }
                }
            }
            return diff == 1;
        }
    };
};