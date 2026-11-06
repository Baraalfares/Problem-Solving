class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        unordered_map<char, int>mp;
        int mx = 0, res = 0;
        while(j < s.size()){
            mp[s[j]]++;
            mx = max(mp[s[j]], mx);
            while(j - i + 1 - mx > k){
                mp[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};