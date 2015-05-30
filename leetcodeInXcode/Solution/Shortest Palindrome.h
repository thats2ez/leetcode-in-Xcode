//
//  Shortest Palindrome.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/25/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        for (int i = n; i < 2 * n - 1; i++) {
            cout << i << endl;
            int d = i - n; // chars to be excluded from right
            int j = n - d; // number of chars to be considered
            if (isPalindrome(s, 0, j)) {
                return buildPalindrome(s, i);
            }
        }
        
        return buildPalindrome(s, 2 * n - 1);
    }

private:
    bool isPalindrome(const string &s, int i, int j) {
        j--;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    string buildPalindrome(const string &s, int k) {
        string result;
        result.reserve(k);
        int n = s.size();
        for (int i = 0; i < k - n; i++) {
            result += s[n - 1 - i];
        }
        result += s;
        return result;
    }
};
