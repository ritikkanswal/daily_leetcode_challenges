class Solution {
public:
    bool static cmp(string x,string y)
    {
        if(x.size()==y.size())
            return x<y;
        return x.size()<y.size();
    }
    string kthLargestNumber(vector<string>& nums, int k) {
       
        sort(nums.rbegin(),nums.rend(),cmp);
        
        return nums[k-1];
    }
};