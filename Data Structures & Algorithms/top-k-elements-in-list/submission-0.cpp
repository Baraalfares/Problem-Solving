class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        vector<vector<int>>vec(nums.size() + 1);
        vector<int>ans;
        for(int num : nums){
            freq[num]++;
        }
        for(auto &[num, count] : freq){
            vec[count].push_back(num);
        }
        for(int i = nums.size() ; i >= 1 && k > 0; i--){
            for(int val : vec[i]){
                ans.push_back(val);
                k--;
                if(!k) break;
            }
        }
        return ans;
    }
};
