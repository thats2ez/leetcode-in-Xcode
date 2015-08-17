//
//  Add Digits.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 8/16/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Add_Digits_h
#define Add_Digits_h

class Solution {
public:
    int addDigits(int num) {
        while (num > 9) {
            num = addDigitsHelper(num);
        }
        return num;
    }
    
private:
    int addDigitsHelper(int num) {
        int result = 0;
        while (num > 0) {
            result += num % 10;
            num /= 10;
        }
        return result;
    }
};

#endif /* Add_Digits_h */
