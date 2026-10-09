class Solution {
   public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        int maxi = 0;
        for (vector<int> &bricks : wall) {
            for (int j = 1; j < bricks.size(); j++) {
                bricks[j] += bricks[j - 1];
                mp[bricks[j - 1]]++;
                maxi = max(mp[bricks[j - 1]], maxi);
            }
        }
        return wall.size() - maxi;
    }
};