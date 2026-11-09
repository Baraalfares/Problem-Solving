class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i = 0, j = 0, longest = -1;
        int sum = 0, target = 0, n = nums.size();
        for(int num : nums)
            target += num;
        target -= x;
        while(j < nums.size()){
            sum += nums[j];

            while(i <= j && sum > target){
                sum -= nums[i];
                i++;
            }
            if(sum == target)
                longest = max(longest, j - i + 1);
            j++;
        }
        return longest == -1 ? longest : n - longest;
    }
};
