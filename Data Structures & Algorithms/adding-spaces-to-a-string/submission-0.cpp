class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int i = 0;
        int j = 0;
        while(i < s.size()){
            if(j < spaces.size() && i == spaces[j]){
                res += ' ';
                j++;
            }
            res += s[i];
            i++;
        }
        return res;
    }
};