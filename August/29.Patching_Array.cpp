class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long reach=0;
        int cnt=0;
        int i=0;
        while(reach<n)
        {
            if(i<nums.size() and reach+1>=nums[i])
            {
                reach+=nums[i++];
            }
            else
            {
                reach+=reach+1;
                cnt++;
            }
        }
        return cnt;
    }
};