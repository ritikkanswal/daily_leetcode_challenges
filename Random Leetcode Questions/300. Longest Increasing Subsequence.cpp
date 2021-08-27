class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            int val=nums[i];
            auto x=lower_bound(res.begin(),res.end(),val);
            if(x!=res.end())
            {
                *x=nums[i];
            }
            else
                res.push_back(nums[i]);
        }
        return res.size();
    }
};