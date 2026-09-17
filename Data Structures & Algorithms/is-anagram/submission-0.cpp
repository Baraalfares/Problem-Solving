class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, int> angram;

        for(char c : s){
            angram[c]++;
        }
        for(char c : t){
            angram[c]--;
        }
        for(auto it : angram){
            if(it.second != 0)
                return false;
        }
        return true;
    }
};
