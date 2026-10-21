class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 2;
        for(int i = 2 ; i < nums.size() ; i++){
            if(nums[i] != nums[write - 2]){
                nums[write] = nums[i];
                write++;
            }
        }
        return write;
    }
};