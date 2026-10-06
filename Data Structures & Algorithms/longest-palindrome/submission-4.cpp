class Solution {
public:
    int longestPalindrome(string s) {
        int freq[128] = {0};
        bool odd = false;
        int count = 0;
        for(char c : s){
            freq[c]++;
        }
        for(int i : freq){
            if(i % 2 == 0){
                count += i;
            }
            else{
                odd = true;
                count += i -1;
            }
        }
        if(odd){
            count++;
        }
        return count;
    }
};