class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int i = 0;
        int j = 0;
        unordered_map<char,int>mp;
        int mx = 0;
        while(j < s.size()){
            mp[s[j]]++;

            if(mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            mx = max(mx, j - i + 1);
            j++;
        }
        return mx;
    }
};
