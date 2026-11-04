class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int>counts(2, 0);
        int maxi = 0;
        int i = 0, j = 0;
        while(j < nums.size()){
            counts[nums[j]]++;
            while(counts[0] > 1){
                counts[nums[i]]--;
                i++;
            }
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};
