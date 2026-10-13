class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int count = 1;
        int maxi = 0;
        for(int num : nums){
            if(st.count(num - 1))
                continue;
            int curr = num;
            count = 1;
            while(st.count(curr + 1)){
                curr++;
                count++;
            }
            maxi = max(count, maxi);
        }
        return maxi;
    }
};
