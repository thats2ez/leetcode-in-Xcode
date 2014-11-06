class Solution {
public:
//    int longestConsecutive(vector<int> &num) {
//        if (num.empty())
//            return 0;
//        sort(num.begin(), num.end());
//        int longest = 1, cur = 1;
//        for (int i=1; i < num.size(); i++) {
//            if (num[i] == num[i-1] + 1) {
//                longest = max(longest, ++cur);
//            } else if (num[i] != num[i-1]) {
//                cur = 1;
//            }
//        }
//    
//        return longest;
//    }

    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> found;
        for (int i : num) {
            found[i] = true;
        }
        int longest = 0;
        while (!found.empty()) {
            int cur = 1;
            for (int i = found.begin()->first - 1; found.find(i) != found.end(); i--) {
                cur++;
                found.erase(found.find(i));
            }
            for (int i = found.begin()->first + 1; found.find(i) != found.end(); i++) {
                cur++;
                found.erase(found.find(i));
            }
            found.erase(found.begin());
            longest = max(longest, cur);
        }
        return longest;
    }
};