class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long> dp(n, 0);
        dp[n - 1] = questions[n - 1].front();
        for (int i = n - 2; i >= 0; --i) {
            int points = questions[i].front();
            int skip = questions[i].back();
            dp[i] = max(points + (i + skip + 1 < n ? dp[i + skip + 1] : 0),
                        dp[i + 1]);
        }
        return dp.front();
    }
};