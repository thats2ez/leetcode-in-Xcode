//
//  Coins in a Line.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/30/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        return n % 3;
    }
};
