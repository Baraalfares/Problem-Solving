class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
        vector<string>vec;

        stringstream ss(s);
        string word;
        while(ss >> word){
            vec.push_back(word);
        }

        if(vec.size() != pattern.size())
            return false;
        for(int i = 0 ; i < pattern.size() ; i++){
            char c = pattern[i];
            string word = vec[i];

            if((mp1.count(c) && mp1[c] != word) ||
            mp2.count(word) && mp2[word] != c){
                return false;
            }         
            mp1[c] = word;
            mp2[word] = c;
        }
        return true;
    }
};