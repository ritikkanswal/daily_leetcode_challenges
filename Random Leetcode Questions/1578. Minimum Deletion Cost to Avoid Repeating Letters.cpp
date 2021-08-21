class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n=cost.size();
        int sum=0;
        int tmpSum=0;
        int i=0;
        while(i<n)
        {
            char x=s[i];
            int ma=-1;
            while(i<n and s[i]==x)
            {
                sum+=cost[i];
                ma=max(ma,cost[i]);
                i++;
            }
            tmpSum+=ma;
        }
        return sum-tmpSum;
    }
};