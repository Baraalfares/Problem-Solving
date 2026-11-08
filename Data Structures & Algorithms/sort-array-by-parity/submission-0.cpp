class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0, i = 0;
        while(j < nums.size()){
            if(nums[j] % 2 == 0){
                swap(nums[j], nums[i]);
                i++;
            }
            j++;
        }
        return nums;
    }
};