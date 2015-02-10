//
//  Letter Combinations of a Phone Number.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 2/9/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> comb{""};
        for (int i = 0; i < digits.size(); i++) {
            vector<string> temp;
            for (char c : letters(digits[i])) {
                vector<string> addOne = append(comb, c);
                temp.insert(temp.end(), begin(addOne), end(addOne));
            }
            comb = temp;
        }
        return comb;
    }
    
private:
    string letters(char digit) {
        switch(digit) {
            case '2':
                return "abc";
            case '3':
                return "def";
            case '4':
                return "ghi";
            case '5':
                return "jkl";
            case '6':
                return "mno";
            case '7':
                return "pqrs";
            case '8':
                return "tuv";
            case '9':
                return "wxyz";
            case '0':
                return " ";
            default:
                return "";
        }
    }
    
    vector<string> append(const vector<string>& comb, char c) {
        vector<string> result;
        for (int i = 0; i < comb.size(); i++) {
            result.push_back(comb[i] + c);
        }
        return result;
    }
};