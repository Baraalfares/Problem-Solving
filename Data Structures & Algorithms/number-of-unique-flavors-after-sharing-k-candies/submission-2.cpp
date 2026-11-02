class Solution {
   public:
    int shareCandies(vector<int>& candies, int k) {
        unordered_map<int, int> count;
        int j = 0;
        int i = 0;
        int ans = 0;
        for (int candy : candies) {
            count[candy]++;
        }
        int unique = count.size();
        if (k == 0) return unique;
        while (j < candies.size()) {
            count[candies[j]]--;
            if (count[candies[j]] == 0) unique--;
            if (j - i + 1 == k) {
                ans = max(ans, unique);
                if (count[candies[i]] == 0) {
                    unique++;
                }
                count[candies[i]]++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
