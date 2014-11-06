class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        int result = 0;
        height.push_back(0);
        for (int i=0; i < height.size(); ) {
            if (s.empty() || height[i] >= height[s.top()]) {
                s.push(i++);
            } else {
                int top = s.top();
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                int area = height[top] * width;
                result = max(result, area);
            }
        }
        return result;
    }
};