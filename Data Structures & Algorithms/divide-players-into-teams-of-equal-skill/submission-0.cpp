class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size(), l = 0, r = n - 1;
        long long res = 0;
        int target = skill[0] + skill[n - 1];
        while(l < r){
            int sum = skill[l] + skill[r];
            if(sum != target)
                return -1;
            res += (skill[l] * skill[r]);
            l++; r--;
        }
        return res;
    }
};
