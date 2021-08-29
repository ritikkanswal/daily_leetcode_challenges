class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mi=INT_MAX;
        for(int i=1;i<nums.size();i++)
        {
            mi=min(mi,nums[i]-nums[i-1]);
        }
        return mi;
    }
};