class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char,int>mp;
        int sum = 0;
        int current = 0;
        for(int i = 0 ; i < keyboard.size() ; i++){
            mp[keyboard[i]] = i;
        }
        for(int i = 0 ; i < word.size() ; i++){
            sum += abs(mp[word[i]] - current);
            current = mp[word[i]];
        }
        return sum;
    }
};
