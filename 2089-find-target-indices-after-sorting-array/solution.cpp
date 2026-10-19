class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int freq[101] = {0};
        int count = 0;
        vector<int>res;
        for(int num : nums){
            freq[num]++;
            if(num < target)
                count++;
        }
        while(freq[target]--){
            res.push_back(count);
            count++;
        }
        return res;
    }
};