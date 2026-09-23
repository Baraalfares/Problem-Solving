class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(j < s.size() && s[j] != ' '){
                j++;
            }
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
    }
};
