class Solution {
public:
    vector<int> vec = vector<int>(46, -1);
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        if(vec[n] != -1)
            return vec[n];
        vec[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return vec[n];
    }
};