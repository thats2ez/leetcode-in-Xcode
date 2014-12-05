//
//  Word Ladder II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/3/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, char> visited;
        BiDirectBFS b1(dict, visited, '1', start), b2(dict, visited, '2', end);
        int length = ladderLength(b1, b2);
        vector<vector<string>> result = paths(b1, b2);
        return result;
    }
    
private:
    class BiDirectBFS;
    
    vector<vector<string>> paths(class BiDirectBFS &b1, class BiDirectBFS &b2) {
        vector<vector<string>> results;
        unordered_set<string> intersection = b1.intersection.empty() ? b2.intersection : b1.intersection;
        
        decltype(results) paths1, paths2;
        getBFSReversePaths(b1, intersection, paths1);
        getBFSReversePaths(b2, intersection, paths2);
        
        unordered_map<string, vector<decltype(results.begin())>> paths2WithBegin;
        for (auto it = paths2.begin(); it != paths2.end(); it++) {
            if (paths2WithBegin.find(it->front()) == paths2WithBegin.end()) {
                paths2WithBegin[it->front()] = vector<decltype(results.begin())>();
            }
            paths2WithBegin[it->front()].push_back(it);
        }
        for (vector<string> path : paths1) {
            string end = path.front();
            reverse(path.begin(), path.end());
            path.pop_back();
            for (decltype(results.begin()) it : paths2WithBegin[end]) {
                vector<string> completePath = path;
                completePath.insert(completePath.end(), it->begin(), it->end());
                results.push_back(completePath);
            }
        }
        return results;
    }
    
    // get all bfs path from end to start
    void getBFSReversePaths(class BiDirectBFS &b, unordered_set<string> &intersection, vector<vector<string>> &results) {
        for (string word : intersection) {
            results.push_back(vector<string>(1, word));
        }
        for (int i = 0; i < b.level - 1; i++) {
            vector<vector<string>> temp;
            for (vector<string> path : results) {
                unordered_set<string> &parents = b.parent[path.back()];
                for (auto it = parents.begin(); it != parents.end(); it++) {
                    path.push_back(*it);
                    temp.push_back(path);
                    path.pop_back();
                }
            }
            swap(results, temp);
        }
        for (auto it = results.begin(); it != results.end(); it++) {
            if (it->back() != b.start) {
                it = results.erase(it) - 1;
            }
        }
    }
    
    int ladderLength(BiDirectBFS &b1, BiDirectBFS &b2) {
        unordered_map<string, char> visited;
        while (b1.hasNext() && b2.hasNext()) {
            if (b1.advanceLevel() || b2.advanceLevel()) {
                return b1.level + b2.level - 1;
            }
        }
        return 0;
    }
    
    class BiDirectBFS {
    public:
        BiDirectBFS(unordered_set<string> &dict, unordered_map<string, char> &visited, char key, string first):
        visited(visited), key(key), dict(dict) {
            largeDict = (dict.size() * first.length() > 26 * first.length());
            q.push(first);
            start = first;
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
                    vector<string> neighbors;
                    getNeighbors(s, neighbors);
                    for (auto it = begin(neighbors); it != end(neighbors); it++) {
                        parent[*it].insert(s);
                        q.push(*it);
                    }
                } else if (it->second != key) {
                    // if has visited by the other queue
                    intersection.insert(s);
                }
            }
            return !intersection.empty();
        }
        
        bool hasNext() {
            return !q.empty();
        }
        
        string start;
        int level = 0;
        unordered_set<string> intersection;
        unordered_map<string, unordered_set<string>> parent;
        
    private:
        queue<string> q;
        char key;
        bool largeDict;
        unordered_map<string, char> &visited;
        unordered_set<string> &dict;
        
        void getNeighbors(string s, vector<string> &words) {
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