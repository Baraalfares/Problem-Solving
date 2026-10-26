class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(), l = 0, r = n - 1;
        while(l < r && s[r] == s[l]){
            char c = s[l];
            while(l <= r && s[l] == c)
                l++;
            while(l <= r && s[r] == c)
                r--;
        }
        return r - l + 1;
    }
};
