class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1000000007;
        int curr = 0;
        long long ans = 0;
        int odd = 0;
        int even = 0;
        for(int num : arr){
            curr += num;
            if(curr % 2 == 1){
                ans++;
                ans += even;
                odd++;
            }
            else{
                ans += odd;
                even++;
            }
        }
        return ans % MOD;
    }
};