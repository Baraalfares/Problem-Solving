class Solution {
public:
    bool isPathCrossing(string path) {
        int count = 0;
        set<pair<int,int>>st;
        pair<int,int>prev = {0,0};
        st.insert(prev);
        for(char c : path){
            if(c == 'N')
                prev.second++;
            else if(c == 'E')
                prev.first++;
            else if(c == 'S')
                prev.second--;
            else
                prev.first--;
            if(st.find(prev) != st.end())
                return true;
            st.insert(prev);
        }
        return false;
    }
};