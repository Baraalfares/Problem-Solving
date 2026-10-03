class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int freq[501] = {0};
        for(int num : nums)
            freq[num]++;
        for(int num : nums){
            if(freq[num] % 2 != 0)
                return false;
        }
        return true;
    }
};