class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int maxi = 0;
        int maxelem = 0;
        for(int num : nums){
            mp[num]++;
            if(maxi < mp[num]){
                maxi = mp[num];
                maxelem = num;
            }
        }
        int leftcount = 0;
        for(int i = 0 ; i < n - 1; i++){
            if(nums[i] == maxelem)
                leftcount++;
            int rightcount = mp[maxelem] - leftcount;
            int leftsz = i + 1;
            int rightsz = n - leftsz;
            if(2 * leftcount > leftsz && 2 * rightcount > rightsz)
                return i;
        }
        return -1;
    }
};