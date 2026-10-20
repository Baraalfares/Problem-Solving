class Solution {
   public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top = 0, bot = 0;
        long long ans = LLONG_MAX;
        int n = grid[0].size();

        for (int val : grid[0]) {
            top += val;
        }

        for (int i = 0; i < n; i++) {
            top -= grid[0][i];
            ans = min(ans, max(top, bot));
            bot += grid[1][i];
        }

        return ans;
    }
};
