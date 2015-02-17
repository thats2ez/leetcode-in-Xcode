class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n <= 0) return 0;
        
        int total = 0, sum = INT_MIN, min_total = 0;
        for (int i = 0; i < n; i++) {
            total += A[i];
            sum = max(sum, total - min_total);
            min_total = min(min_total, total);
        }
        return sum;
    }
    
};