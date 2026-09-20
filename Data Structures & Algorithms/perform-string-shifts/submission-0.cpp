class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int amount = 0;
        int n = s.size();
        for(int i = 0 ; i < shift.size() ; i++){
            if(shift[i][0] == 0)
                amount -= shift[i][1];
            else
                amount += shift[i][1];
        }
        amount = ((amount % n) + n) % n;
        return s.substr(n - amount) + s.substr(0, n - amount);
    }
};
