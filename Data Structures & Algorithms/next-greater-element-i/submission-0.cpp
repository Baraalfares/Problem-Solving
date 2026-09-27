class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(int i = 0 ; i < nums2.size() ; i++){
            mp[nums2[i]] = i;
        }
        for(int i = 0 ; i < nums1.size() ; i++){
            bool flag = 0;
            for(int j = mp[nums1[i]] ; j < nums2.size() ; j++){
                if(nums2[j] > nums1[i]){
                    res.push_back(nums2[j]);
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                res.push_back(-1);
        }
        return res;
    }
};