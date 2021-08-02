class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>ump;
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            
            if(ump[target-nums[i]]!=0)
            {
                v.push_back(i);
                v.push_back(ump[target-nums[i]]-1);
                return v;
            }
            ump[nums[i]]=i+1;
        }
        return v;
        
    }
};