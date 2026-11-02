class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        int mini = INT_MAX;
        while(j < nums.size()){
            if(j - i + 1 == k){
                int sum = nums[j] - nums[i];
                mini = min(sum, mini);
                i++;
            }
            j++;
        }
        return mini;
    }
};