class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[] = {0,0};
        for(int student : students){
            count[student]++;
        }
        for(int i = 0 ; i < sandwiches.size() ; i++){
            if(count[sandwiches[i]] == 0)
                break;
            count[sandwiches[i]]--;
        }
        return count[0] + count[1];
    }
};