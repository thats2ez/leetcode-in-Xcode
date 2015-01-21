//
//  Largest Number.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 1/20/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> str;
        str.reserve(num.size());
        for (auto it = begin(num); it != end(num); it++) {
            str.push_back(to_string(*it));
        }
        sort(begin(str), end(str), my_greater);
        return clean(accumulate(begin(str), end(str), string()));
    }
    
private:
//    static bool my_greater(const string &str1, const string &str2) {
//        if (str1.length() == str2.length()) {
//            return str1 > str2;
//        }
//        string s, l;
//        bool str1_is_s = true;
//        if (str1.length() < str2.length())
//            s = str1, l = str2;
//        else
//            s = str2, l = str1, str1_is_s = false;
//        int common_length_compare = s.compare(l.substr(0, s.length()));
//        bool result;
//        if (common_length_compare != 0)
//            result = (common_length_compare > 0);
//        else {
//            string exceed_part = l.substr(s.length(), l.length() - s.length() + 1);
//            result = my_greater(s, exceed_part);
//        }
//        return result == str1_is_s;
//    }
    
    static bool my_greater(const string &str1, const string &str2) {
        return str1 + str2 > str2 + str1;
    }
    
    string clean(const string& str) {
        int i = 0;
        for (; i < str.length(); i++) {
            if (str[i] != '0')
                break;
        }
        return i == str.length() ? "0" : str.substr(i, str.length() - i);
    }
};