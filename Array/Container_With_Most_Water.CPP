class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int first = 0;
        int end = n - 1;
        int res = 0;

        while (first < end) {
            res = max(res, min(height[first], height[end]) * (end - first));
            if (height[first] < height[end]) {
                first++;
            } else {
                end--;
            }
        }
        
        return res;
    }
};
