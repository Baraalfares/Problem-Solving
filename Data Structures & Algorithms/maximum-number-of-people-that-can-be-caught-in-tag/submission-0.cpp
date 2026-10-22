class Solution {
public:
    int catchMaximumAmountofPeople(vector<int>& team, int dist) {
        int i = 0;
        int n = team.size();
        int j = 0;
        int count = 0;
        while(i < n && j < n){
            while(i < n && team[i] == 0) i++;
            while(j < n && team[j] == 1) j++;
            if(i >= n || j >= n) break;

            if(abs(i - j) <= dist){
                count++;
                i++;
                j++;
            }
            else{
                if(i < j)
                    i++;
                else if(j < i)
                    j++;
            }
        }
        return count;
    }
};