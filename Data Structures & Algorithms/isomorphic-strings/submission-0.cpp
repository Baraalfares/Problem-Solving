class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, char>mps;
        unordered_map<char, char>mpt;
        for(int i = 0 ; i < s.size() ; i++){
            if(mps.count(s[i]) && mps[s[i]] != t[i])
                    return false;
            else if(mpt.count(t[i]) && mpt[t[i]] != s[i])
                    return false;
            mps[s[i]] = t[i];
            mpt[t[i]] = s[i];
        }
        return true;
    }
};