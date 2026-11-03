class Solution {
public:
    int equalCountSubstrings(string s, int count) {
        int ans = 0, d = 1;

        while(d <= 26 && d * count <= s.size()){
            unordered_map<char,int>mp;
            int i = 0, j = 0;
            int cntr = 0;
            int window = d * count;

            while(j < s.size()){
                mp[s[j]]++;
                if(mp[s[j]] == count) cntr++;
                if(mp[s[j]] == count + 1) cntr--;

                if(j - i + 1 > window){
                    mp[s[i]]--;
                    if(mp[s[i]] == count) cntr++;
                    if(mp[s[i]] == count - 1) cntr--;

                    i++;
                }
                if(j - i + 1 == window && cntr == d){
                    ans++;
                }
                j++;
            }
            d++;
        }
        return ans;
    }
};
