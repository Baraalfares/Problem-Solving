class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int freqs[101] = {0};
        int count = 0;
        for(int num : nums){
            freqs[num]++;
        }
        for(int freq : freqs){
            count += (freq * (freq - 1)) / 2;
        }
        return count;
    }
};