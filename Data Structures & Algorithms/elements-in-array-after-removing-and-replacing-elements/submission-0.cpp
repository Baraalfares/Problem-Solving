class Solution {
   public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < queries.size(); i++) {
            int time = queries[i][0] % (2 * n);
            int idx = queries[i][1];
            if (time < n) {
                if (idx < n - time) {
                    res.push_back(nums[time + idx]);
                } else
                    res.push_back(-1);
            }
            else {
                if(idx < time - n){
                    res.push_back(nums[idx]);
                }
                else
                    res.push_back(-1);
            }
        }
        return res;
    }
};
