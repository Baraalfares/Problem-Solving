class Solution {
public:
    string customSortString(string order, string s) {
        int freq[26] = {0};
        string res = "";
        for(char c : s){
            freq[c - 'a']++;
        }
        for(char c : order){
            while(freq[c - 'a'] > 0){
                res += c;
                freq[c - 'a']--;
            }
        }
        for(char c : s){
            while(freq[c - 'a'] > 0){
                res += c;
                freq[c - 'a']--;
            }
        }
        return res;
    }
};