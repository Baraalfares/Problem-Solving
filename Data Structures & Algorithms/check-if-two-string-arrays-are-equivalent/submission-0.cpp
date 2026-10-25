class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0;
        int j = 0;
        int k = 0;
        int p = 0;
        while(i < word1.size() && j < word2.size()){
            if(word1[i][k] != word2[j][p]) return false;
            p++;
            k++;
            if(k == word1[i].size()){
                i++;
                k = 0;
            }
            if(p == word2[j].size()){
                j++;
                p = 0;
            }
        }
        return i == word1.size() && j == word2.size();
    }
};
