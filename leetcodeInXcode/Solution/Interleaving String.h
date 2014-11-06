class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        unordered_map<char, int> map = countChar(s1, s2);
        for (char c : s3) {
            auto it = map.find(c);
            if (it == map.end()) return false;
            if ( --(it->second) < 0) return false;
        }
        vector<vector<int> > cache = vector<vector<int> >(s1.length() + 1, vector<int>(s2.length() + 1, -1) );
        return dfs(s1, s2, s3, s3.length() - 1, cache);
    }
    
    unordered_map<char, int> countChar(const string &str1, const string &str2) {
        unordered_map<char, int> map;
        for (char c : str1) {
            map[c] += 1;
        }
        for (char c : str2) {
            map[c] += 1;
        }
        return map;
    }
    
    bool dfs(string &s1, string &s2, const string &s3, int n, vector<vector<int> > &cache) {
        if (cache[s1.length()][s2.length()] != -1 ) {
            return cache[s1.length()][s2.length()];
        }
        if (n < 0){
            cache[s1.length()][s2.length()] = 1;
            return true;
        }
        
        
        if ( !s1.empty() && (s1.back() == s3[n])) {
            s1.pop_back();
            if (dfs(s1, s2, s3, n-1, cache)) {
                cache[s1.length()][s2.length()] = 1;
                return true;
            }
            s1.push_back(s3[n]);
        }
        if ( !s2.empty() && (s2.back() == s3[n])) {
            s2.pop_back();
            if (dfs(s1, s2, s3, n-1, cache)) {
                cache[s1.length()][s2.length()] = 1;
                return true;
            }
            s2.push_back(s3[n]);
        }
        cache[s1.length()][s2.length()] = 0;
        return false;
    }
    
//    bool isInterleave(string s1, string s2, string s3) {
//        if (s1.length() + s2.length() != s3.length()) return false;
//        vector<vector<bool> > opt = vector<vector<bool> >(s1.length() + 1, vector<bool>(s2.length() + 1, false) );
//        opt[0][0] = true;
//        for (int i = 0; i <= s1.length(); i++)
//            for (int j = 0; j <= s2.length(); j++)
//                opt[i][j] = ( i > 0 && opt[i-1][j] && (s1[i-1] == s3[i+j-1]))
//                || ( j > 0 && opt[i][j-1] && (s2[j-1] == s3[i+j-1]))
//                || opt[i][j];
//        return opt[s1.length()][s2.length()];
//    }
};