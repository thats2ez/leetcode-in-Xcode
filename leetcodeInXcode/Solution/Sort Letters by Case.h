//
//  Sort Letters by Case.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 6/7/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        partition(letters.begin(), letters.end(), lowerCase);
    }
    
private:
    static bool lowerCase(char c) {
        return c >= 'a' && c <= 'z';
    }
};

