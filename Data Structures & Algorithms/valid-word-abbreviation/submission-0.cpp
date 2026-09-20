class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if(word == abbr)
            return true;
        int i = 0;
        int j = 0;
        while(i < word.size() && j < abbr.size()){
            if(isalpha(abbr[j])){
                if(abbr[j] == word[i]){
                    i++;
                    j++;
                }
                else
                    return false;
            }
            else{
                if(abbr[j] == '0')
                    return false;
                else{
                    string s = "";
                    while(j < abbr.size() && isdigit(abbr[j])){
                        s += abbr[j];
                        j++;
                    }
                    int num = stoi(s);
                    i += num;
                }
            }
        }
        return i == word.size() && j == abbr.size();
    }
};