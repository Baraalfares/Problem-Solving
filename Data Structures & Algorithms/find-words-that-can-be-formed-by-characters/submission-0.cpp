class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int freq[26] = {0};
        int count = 0;
        int res = 0;
        for(char c : chars){
            freq[c - 'a']++;
        }
        for(int i = 0 ; i < words.size() ; i++){
            count = 0;
            if(canForm(words[i], freq))
                res += words[i].size();
        }
        return res;
    }
    bool canForm(const string& word, const int freq[]){
        vector<int> wordfreq(26, 0);
        for(char c : word){
            wordfreq[c - 'a']++;
            if(wordfreq[c - 'a'] > freq[c - 'a'])
                return false;
        }
        return true;
    }
};