class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n > m)
            return isOneEditDistance(t, s);
        if(m - n > 1)
            return false;

        for(int i = 0 ; i < n ; i++){
            if(s[i] != t[i]){
                if(n == m)
                    return s.substr(i + 1) == t.substr(i + 1);
                else if(m > n)
                    return s.substr(i) == t.substr(i + 1);
            }
        }
        return (n + 1) == m;
        
    }
};
