class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        int zeros = 0;
        int ones = 0;
        for(int i = 0 ; i < students.size() ; i++){
            if(students[i] == 1)
                ones++;
            else
                zeros++;
            q.push(students[i]);
        }
        int i = 0;
        while(i < sandwiches.size()){
            if(q.front() == sandwiches[i]){
                q.pop();
                if(sandwiches[i] == 1)
                    ones--;
                else
                    zeros--;
                i++;
            }
            else{
                if(sandwiches[i] == 1 && ones == 0)
                    return zeros;
                else if(sandwiches[i] == 0 && zeros == 0)
                    return ones;
                else{
                    int val = q.front();
                    q.pop();
                    q.push(val);
                }
            }
        }
        return 0;
    }
};