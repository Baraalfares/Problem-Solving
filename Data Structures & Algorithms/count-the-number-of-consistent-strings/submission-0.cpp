class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool freq[26] = {false};
        int count = 0;
        for(char c : allowed){
            freq[c - 'a'] = true;
        }
        for(int i = 0 ; i < words.size() ; i++){
            for(char c: words[i]){
                if(!freq[c - 'a']){
                    count++;
                    break;
                }
            }
        }
        return words.size() - count;
    }
};