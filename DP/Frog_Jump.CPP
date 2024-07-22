class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (n == 0 || stones[1] != 1) return false;

       
        unordered_map<int, unordered_set<int>> dp;
        for (int stone : stones) {
            dp[stone] = unordered_set<int>();
        }
        dp[0].insert(0);

        for (int stone : stones) {
            for (int jump : dp[stone]) {
                for (int step = jump - 1; step <= jump + 1; step++) {
                    if (step > 0 && dp.find(stone + step) != dp.end()) {
                        dp[stone + step].insert(step);
                    }
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};
