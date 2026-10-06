class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        for(int &num : nums){
            if(num == 0)
                zeros++;
            else if(num == 1)
                ones++;
            else
                twos++;
        }

        for(int &num : nums){
            if(zeros > 0){
                zeros--;
                num = 0;
            }
            else if(ones > 0){
                ones--;
                num = 1;
            }
            else{
                twos--;
                num = 2;
            }
        }
    }
};