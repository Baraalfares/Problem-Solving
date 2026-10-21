class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n - 1;
        while(i < j){
            int sum = numbers[j] + numbers[i];
            if(sum == target){
                return {i + 1 , j + 1};
            }
            if(sum > target){
                j--;
            }
            else
                i++;
        }
        return {-1, -1};
    }
};
