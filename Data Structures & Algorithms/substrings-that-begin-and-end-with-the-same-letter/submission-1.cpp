class Solution {
public:
    long long numberOfSubstrings(string s) {
        unordered_map<char, int>mp;
        long long ans = 0;
        for(char c : s){
            mp[c]++;
            ans += mp[c];
        }
        return ans;
    }
};
