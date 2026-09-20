class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int>st;
        int count = 0;
        for(int num : arr){
            st.insert(num);
        }
        for(int num : arr){
            if(st.find(num + 1) != st.end()){
                count++;
            }
        }
        return count;
    }
};
