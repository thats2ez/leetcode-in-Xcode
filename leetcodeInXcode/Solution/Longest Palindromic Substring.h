////
////  Longest Palindromic Substring.h
////  leetcodeInXcode
////
////  Created by Kaiqi on 12/15/14.
////  Copyright (c) 2014 edu.self. All rights reserved.
////
//
//class Solution {
//public:
//    string longestPalindrome(string s) {
//        if (s.empty())
//            return 0;
//        int start = 0;
//        int end = 0;
//        for (int k = int(s.length()/2); k >= 0 && (2*k + 2 > start-end+1); k--) {
//            int array[] = {k, int(s.length()-k-1)};
//            for (int i : array) {
//                for (int j = 1; i - j >= 0 && i + j < s.length(); j++) {
//                    if (s[i-j] == s[i+j]) {
//                        int max = end - start + 1;
//                        int l = 2 * j + 1;
//                        if (l > max) {
//                            start = i - j;
//                            end = i + j;
//                        }
//                    } else {
//                        break;
//                    }
//                }
//                for (int j = 1; i - j >= 0 && i + j - 1 < s.length(); j++) {
//                    if (s[i-j] == s[i+j-1]) {
//                        int max = end - start + 1;
//                        int l = 2 * j;
//                        if (l > max) {
//                            start = i - j;
//                            end = i + j - 1;
//                        }
//                    } else {
//                        break;
//                    }
//                }
//                if (k == int(s.length()-k-1))
//                    break;
//            }
//        }
//        return s.substr(start, end-start+1);
//    }
//};


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return 0;
        }
        int longest = 1, begin = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            int pre = longest;
            longest = max(longest, expandCount(s, i, i));
            longest = max(longest, expandCount(s, i, i+1));
            if (longest != pre) {
                begin = i - (longest - 1)/2;
            }
        }
        return s.substr(begin, longest);
    }
    
private:
    int expandCount(const string &s, int i, int j) {
        int count = i == j ? -1 : 0;
        while (i >= 0 && j < s.length() && s[i--] == s[j++]) {
            count += 2;
        }
        return count;
    }
};