class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, mx = 0;
        unordered_map<char,int>mp;

        while(j < s.size()){
            mp[s[j]]++;

            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }
            mx = max(mx, j - i + 1);
            j++;
        }
        return mx;
    }
};
