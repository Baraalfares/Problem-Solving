class Solution {
public:
    int countElements(vector<int>& arr) {
        bool has[1002] = {false};
        int count = 0;
        for(int num : arr){
            has[num] = true;
        }
        for(int num : arr){
            if(has[num + 1])
                count++;
        }
        return count;
    }
};
