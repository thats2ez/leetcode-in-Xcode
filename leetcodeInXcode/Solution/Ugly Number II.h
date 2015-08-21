//
//  Ugly Number II.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 8/20/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Ugly_Number_II_h
#define Ugly_Number_II_h

class Solution {
public:
    int nthUglyNumber(int n) {
        set<int> window;
        window.insert(1);
        for (int i = 1; i < n; i++) {
            int front = *window.begin();
            safeInsert(window, front, 2);
            safeInsert(window, front, 3);
            safeInsert(window, front, 5);
            window.erase(window.begin());
        }
        return *window.begin();
    }
    
private:
    bool safeInsert(set<int> &window, const int front, const int factor) {
        if (INT_MAX / factor <= front) {
            return false;
        }
        window.insert(front * factor);
        return true;
    }
};

#endif /* Ugly_Number_II_h */
