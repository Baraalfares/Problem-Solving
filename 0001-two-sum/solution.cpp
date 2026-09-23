class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>twosum;
        int sz = nums.size();
        for(int i = 0 ; i < sz ; i++){
            int diff = target - nums[i];
            if(twosum.find(diff) != twosum.end()){
                return {twosum[diff], i};
            }
            twosum[nums[i]] = i;
        }
        return {-1 , -1};
    }
};