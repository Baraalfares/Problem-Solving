class Solution {
public:
    bool isvowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int curr = 0;
        int maxv = 0;
        int i = 0, j = 0;
        while(j < s.size()){
            if(isvowel(s[j]))
                curr++;
            if(j - i + 1 > k){
                if(isvowel(s[i]))
                    curr--;
                i++;
            }
            maxv = max(curr, maxv);
            j++;
        }
        return maxv;
    }
};