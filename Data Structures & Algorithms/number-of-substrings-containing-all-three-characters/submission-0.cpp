class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int j = 0, i = 0, n = s.size();
        int ans = 0;
        while(j < n){
            mp[s[j]]++;
            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                ans += n - j;
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};