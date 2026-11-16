class Solution {
   public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.size(), 0);
        int n = boxes.size();
        int balls = 0, count = 0;
        for (int i = 0; i < n; i++) {
            res[i] += count;
            balls += (boxes[i] - '0');
            count += balls;
        }
        balls = 0;
        count = 0;
        for (int i = n - 1; i >= 0; i--) {
            res[i] += count;
            balls += (boxes[i] - '0');
            count += balls;
        }
        return res;
    }
};