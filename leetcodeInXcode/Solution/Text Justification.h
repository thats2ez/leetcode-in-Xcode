//
//  Text Justification.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/6/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        int end = 0;
        while ( end < words.size()) {
            int start = end;
            int space = L;
            while (end < words.size() && space - int(words[end].length()) >= end - start) {
                space -= words[end++].length();
//                cout << space << " " << words[end].length() << " " << gap << endl;
            }
            string line;
            line.reserve(L);
            result.push_back(makeLine(line, space, words, start, end, end == words.size()));
        }
        return result;
    }
    
    string& makeLine(string &line, int space, vector<string> &words, int start, int end, bool lastLine) {
        int gap = end - start - 1;
        int remaining_space = 0;
        if (lastLine || gap == 0) {
            remaining_space = space - gap;
            space = gap;
        }
        for (int i = start; i < end; i++) {
            line += words[i];
            if (gap == 0)
                break;
            int padding = (space + gap - 1) / gap;
            for (int i=0; i < padding; i++) {
                line += " ";
            }
            space -= padding;
            gap--;
        }
        for (int i=0; i < remaining_space; i++) {
            line += " ";
        }
        return line;
    }
};