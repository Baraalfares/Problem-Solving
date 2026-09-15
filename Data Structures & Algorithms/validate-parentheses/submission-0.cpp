class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c : s){
            if(c == '[' || c == '{' || c == '(')
                st.push(c);
            else if(!st.empty() && c == ']' && st.top() == '[')
                st.pop();
            
            else if(!st.empty() && c == '}' && st.top() == '{')
                st.pop();
            else if(!st.empty() && c == ')' && st.top() == '(')
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};
