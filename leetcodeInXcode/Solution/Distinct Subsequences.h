class Solution {
public:
    int numDistinct(string S, string T) {
        vector<vector<int> > opt(S.size()+1, vector<int>(T.size()+1, 0));
        opt[0][0] = 1;
        for (int i=1; i<S.size()+1; i++) {
            opt[i][0] = 1;
            for (int j=1; j<T.size()+1; j++) {
                opt[i][j] = opt[i-1][j];
                if (S[i-1] == T[j-1])
                    opt[i][j] += opt[i-1][j-1];
            }
        }
        return opt[S.size()][T.size()];
    }
};