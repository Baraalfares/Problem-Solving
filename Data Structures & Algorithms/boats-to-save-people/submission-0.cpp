class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size(), l = 0, r = n - 1;
        int res = 0;
        while(l <= r){
            int wght = people[l] + people[r];
            if(wght <= limit)
                l++;
            r--;
            res++;
        }
        return res;
    }
};