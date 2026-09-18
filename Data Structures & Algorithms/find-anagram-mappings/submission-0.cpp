class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int>mp;
        vector<int>res(n , 0);
        for(int i = 0 ; i < nums2.size() ; i++){
            mp[nums2[i]] = i;
        }
        for(int i = 0 ; i < nums1.size() ; i++){
            res[i] = mp[nums1[i]];
        }
        return res;
    }
};
