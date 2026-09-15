class Solution {
public:
    int calPoints(vector<string>& operations) {
        // stack<int>score;
        // int size = operations.size();
        // for(int i = 0; i < size; i++){
        //     if(operations[i] == "+"){
        //         int num = score.top();
        //         score.pop();
        //         int nw = score.top() + num;
        //         score.push(num);
        //         score.push(nw);
        //     }
        //     else if(operations[i] == "D"){
        //         score.push(score.top() * 2);
        //     }
        //     else if(operations[i] == "C")
        //         score.pop();
        //     else
        //         score.push(stoi(operations[i]));
        // }
        // int sum = 0;
        // while(!score.empty()){
        //     sum += score.top();
        //     score.pop();
        // }
        vector<int>score;
        for(int i = 0 ; i < operations.size() ; i++){
            if(operations[i] == "+"){
                int last = score.back();
                int secondLast = score[score.size() - 2];
                score.push_back(last + secondLast);
            }
            else if(operations[i] == "C")
                score.pop_back();
            else if(operations[i] == "D")
                score.push_back(score.back() * 2);
            else
                score.push_back(stoi(operations[i]));
        }

        int sum = accumulate(score.begin(), score.end(), 0);
        return sum;
    }
};