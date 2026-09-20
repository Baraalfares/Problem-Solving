class Solution {
   public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0].front();
        int maxi = arrays[0].back();
        int max_diff = 0;
        for (int i = 1; i < arrays.size(); i++) {
            max_diff = max(max_diff, maxi - arrays[i].front());
            max_diff = max(max_diff, arrays[i].back() - mini);
            mini = min(mini, arrays[i].front());
            maxi = max(maxi, arrays[i].back());
        }
        return max_diff;
    }
};
