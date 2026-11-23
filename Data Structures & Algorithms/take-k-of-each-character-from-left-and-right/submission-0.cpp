class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        int i = 0, j = 0, n = s.size();
        unordered_map<char,int>mp;
        int cnt = 0;
        for(char c : s) mp[c]++;
        if(mp['a'] < k || mp['b'] < k || mp['c'] < k) return -1;

        int maxwndw = 0;
        while(j < n){
            mp[s[j]]--;
            while(mp['a'] < k || mp['b'] < k || mp['c'] < k){
                mp[s[i]]++;
                i++;
            }
            maxwndw = max(maxwndw, j - i + 1);
            j++;
        }
        return n - maxwndw;
    }
};
