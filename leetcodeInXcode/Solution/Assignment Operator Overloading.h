//
//  Assignment Operator Overloading.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 5/30/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }
    
    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if (&object == this) return *this;
        delete this->m_pData;
        if (!object.m_pData) {
            this->m_pData = nullptr;
        } else {
            this->m_pData = (char *)malloc(strlen(object.m_pData));
            memcpy(this->m_pData, object.m_pData, strlen(object.m_pData));
        }
        return *this;
    }
};
