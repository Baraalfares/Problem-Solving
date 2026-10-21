class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool sorted = true;
        char maxi = 'a';
        char mini = 'z';
        for(int i = 0 ; i < n - 1 ; i++){
            if(s[i] > s[i + 1]) 
                sorted = false;
            maxi = max(maxi, max(s[i], s[i + 1]));
            mini = min(mini, min(s[i], s[i + 1]));
        }

        cout << maxi << endl;
        cout << mini << endl;
        if(sorted) return 0;
        if(n == 2) return -1;

        if(s[0] == mini || s[n - 1] == maxi)
            return 1;

        for(int i = 0 ; i < n - 1 ; i++){
            if(s[i] == mini)
                return 2;
        }
        for(int i = 1 ; i <= n ; i++){
            if(s[i] == maxi)
                return 2;
        }
        
        return 3;

    }
};