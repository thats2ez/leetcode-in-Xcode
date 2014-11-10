//
//  Reverse Words in a String.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/9/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    void reverseWords(string &s) {
        vector<string> words;
        int i=0;
        while(i < s.length()){
            // go through spaces
            while(i < s.length() && s[i] == ' ')
                i++;
            int start = i;
            // go through chars
            while(i < s.length() && s[i] != ' ')
                i++;
            int length = i - start;
            if(length > 0)
                words.push_back(s.substr(start, length));
        }
        s.clear();
        for(auto it = words.rbegin(); it != words.rend(); it++) {
            s += *it;
            s += " ";
        }
        if(s.length() > 0)
            s.erase(s.end()-1);
    }
};