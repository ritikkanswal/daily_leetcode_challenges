class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int zero=0,miR=INT_MAX,miC=INT_MAX,cnt=0;
        for(auto x:ops)
        {
            if(x[0]==0||x[1]==0)
                cnt++;
            else
            {
                miR=min(miR,x[0]);
                miC=min(miC,x[1]);
            }
        }
        if(miR==INT_MAX||miC==INT_MAX)
            return m*n;
        return (miR*miC);
    }
};