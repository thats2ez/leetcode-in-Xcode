//
//  Simplify Path.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 12/15/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v = split(path);
        simplify(v);
        return merge(v);
    }
    
    vector<string> split(string path) {
        int i = 0;
        vector<string> result;
        path += '/';
        for(int j = 0; j < path.length(); j++) {
            if (path[j] == '/') {
                if (i < j) {
                    result.push_back(path.substr(i, j - i));
                }
                i = j + 1;
            }
        }
        return result;
    }
    
    void simplify(vector<string> &v) {
        for (auto it = v.begin(); it != v.end();) {
            if (*it == ".") {
                it = v.erase(it);
            } else if (*it == "..") {
                if (it != v.begin()) {
                    it = v.erase(prev(it), next(it));
                } else {
                    it = v.erase(it);
                }
            } else {
                it++;
            }
        }
    }
    
    string merge(vector<string> &v) {
        string path;
        for (auto it = v.begin(); it != v.end(); it++) {
            path += "/" + *it;
        }
        return path.empty() ? "/" : path;
    }
};