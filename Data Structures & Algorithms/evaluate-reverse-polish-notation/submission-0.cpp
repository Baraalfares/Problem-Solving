class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> result;
        int size = tokens.size();
        for (int i = 0; i < size; i++) {
            if (tokens[i] == "+") {
                int val = result.top();
                result.pop();
                result.top() = result.top() + val;
            } else if (tokens[i] == "-") {
                int val = result.top();
                result.pop();
                result.top() = result.top() - val;
            } else if (tokens[i] == "*") {
                int val = result.top();
                result.pop();
                result.top() = result.top() * val;
            } else if (tokens[i] == "/") {
                int val = result.top();
                result.pop();
                result.top() = result.top() / val;
            } else {
                result.push(stoi(tokens[i]));
            }
        }
        return result.top();
    }
};
