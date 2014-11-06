//
//  Scramble String.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 11/5/14.
//  Copyright (c) 2014 edu.self. All rights reserved.
//

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        vector<vector<vector<bool> > > opt(s1.length()+1, vector<vector<bool> >(s1.length(), vector<bool>(s1.length(), false)));
        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s1.length(); j++) {
                opt[1][i][j] = (s1[i] == s2[j]);
            }
        }
        for (int n = 2; n < s1.length() + 1; n++) {
            for (int i = 0; i < s1.length() - n + 1; i++) {
                for (int j = 0; j < s1.length() - n + 1; j++) {
                    for (int k = 1; k < n; k++) {
                        if ((opt[k][i][j] && opt[n-k][i+k][j+k]) ||
                             (opt[k][i][j+n-k] && opt[n-k][i+k][j])) {
                            opt[n][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return opt[s1.length()][0][0];
    }
};
