class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        bool flag=0;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i+1]>nums[i])
            {
                int tmp=INT_MAX;
                int idx=i+1;
                for(int j=i+1;j<nums.size();j++)
                {
                    if(nums[i]<nums[j] and tmp>nums[j])
                    {
                        tmp=nums[j];
                        idx=j;
                    }
                }
                flag=1;
                swap(nums[i],nums[idx]);
                sort(nums.begin()+i+1,nums.end());
                break;
            }
        }
        if(!flag)
            sort(nums.begin(),nums.end());
    }
};