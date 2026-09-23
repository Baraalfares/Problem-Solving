class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int left = 0;
        int right = 0;
        while(left < word1.size() && right < word2.size()){
            res += word1[left++];
            res += word2[right++];
        }
        if(left < word1.size()){
            res += word1.substr(left);
        }
        else if(right < word2.size()){
            res += word2.substr(right);
        }
        return res;
    }
};