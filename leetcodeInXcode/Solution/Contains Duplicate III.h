//
//  Contains Duplicate III.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/11/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef Contains_Duplicate_III_h
#define Contains_Duplicate_III_h

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0 || k < 1) return false;
        
        typedef uint64_t point;
        
        unordered_map<point, point> pos;
        for (int i = 0; i < nums.size(); i++) {
            int x = floor(double(i) / k);
            int y = t ? floor(double(nums[i]) / t) : nums[i];
            cout << x << " " << y << endl;
            int arr_x[] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
            int arr_y[] = {0, 1, -1, 0, 1, -1, 0, 1, -1};
            for (int j = 0; j < sizeof(arr_x); j++) {
                auto it = pos.find(make_point(x + arr_x[j], y + arr_y[j]));
                if (it == pos.end()) {
                    continue;
                }
                point p = it->second;
                cout << getX(p) << " " << getY(p) << endl;
                if (abs(getX(p) - i) <= k
                    && abs(getY(p) - nums[i]) <= t) {
                    return true;
                }
            }
            pos[make_point(x, y)] = make_point(i, nums[i]);
        }
        return false;
    }
    
private:
    uint64_t make_point(int32_t x, int32_t y) {
        return (uint64_t(x) << 32) | uint64_t(uint32_t(y));
    }
    
    int32_t getX(uint64_t pt) {
        return int32_t(pt >> 32);
    }
    
    int32_t getY(uint64_t pt) {
        return int32_t((pt << 32) >> 32);
    }
};
#endif /* Contains_Duplicate_III_h */
