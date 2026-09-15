class Solution {
   public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans = nums;
        //alternative solution
        //vector<int>ans(n * 2 , 0);
        for (int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
            //ans[i] = nums[i % n];
        }
        return ans;
    }
};