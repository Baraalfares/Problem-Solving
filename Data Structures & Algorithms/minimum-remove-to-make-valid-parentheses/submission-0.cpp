class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int balanced = 0;
        int n = s.size();
        string ans = "";
        for(char &c : s){
            if(c == '(')
                balanced++;
            else if(c == ')'){
                if(balanced == 0)
                    c = '#';
                else
                    balanced--;
            }
        }
        int i = n - 1;
        while(i >= 0 && balanced > 0){
            if(s[i] == '('){
                s[i] = '#';
                balanced--;
            }
            i--;
        }
        for(char c : s){
            if(c != '#')
                ans += c;
        }
        return ans;
    }
};
