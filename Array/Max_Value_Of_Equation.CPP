
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int ans = INT_MIN;
        
        for(int i=1; i<n; i++){
            if(points[i][0]-points[i-1][0]<=k)
                ans = max(ans, (points[i][0] - points[i-1][0] + points[i][1] + points[i-1][1]));
        }
        
        return ans;
    }
};

