class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int>mp;
        int maxi = -1;
        for(int i = 0 ; i < s.size() ; i++){
            if(mp.find(s[i]) == mp.end())
                mp[s[i]] = i;
            else
                maxi = max(i - mp[s[i]] - 1, maxi);
        }
        return maxi;
    }
};