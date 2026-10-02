class Solution {
public:
    bool isodd(int num){
        return num % 2 != 0;
    }
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() - 1; i++){
            if(isodd(nums[i]) && isodd(nums[i + 1]))
                return false;
            else if(!isodd(nums[i]) && !isodd(nums[i + 1]))
                return false;
        }
        return true;
    }
};