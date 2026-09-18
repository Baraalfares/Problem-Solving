class Solution {
public:
    bool isSubsequence(string s, string t) {
        int count = 0;
        for(int i = 0 ; i < t.size() ; i++){
            if(s[count] == t[i])
                count++;
            if(count == s.size())
                return true;
        }
        return false;
    }
};