class Solution {
public:
    bool visited[100005];
    int arrayNesting(vector<int>& nums) {
        int ma=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(!visited[i])
            {
                int cnt=0;
                while(!visited[i])
                {
                    cnt++;
                    visited[i]=1;
                    i=nums[i];
                }
                ma=max(ma,cnt);
            }
        }
        return ma;
    }
};