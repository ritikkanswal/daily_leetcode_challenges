class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>ump;
        int cnt=0,sum=0;
        ump[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(ump[sum-k])
            {
                cnt+=ump[sum-k];
            }
            ump[sum]++;
        }
        return cnt;
    }
};