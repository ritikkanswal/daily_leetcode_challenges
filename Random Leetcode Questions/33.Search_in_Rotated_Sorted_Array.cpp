class Solution {
public:
    int binarysearch(vector<int>& nums,int left,int right)
    {
        if(right<left) return 0;
        int mid=left+(right-left)/2;
        int N=nums.size();
        int prev=nums[(mid+N-1)%N];
        int next=nums[(mid+1)%N];
        if(nums[mid]<prev and nums[mid]<next)
            return mid;
        if(nums[0]>nums[mid])
            return binarysearch(nums,left,mid-1);
        else
            return binarysearch(nums,mid+1,right);
    }
    int search(vector<int>& nums,int target) {
        int pivot=binarysearch(nums,0,nums.size()-1);
        if(pivot!=0)
        {
            int x=lower_bound(nums.begin(),nums.begin()+pivot,target)-nums.begin();
            if(x>=nums.size())
                return -1;
            if(nums[x]==target)
                return x;
        }
        
        int x=lower_bound(nums.begin()+pivot,nums.end(),target)-nums.begin();
        if(x>=nums.size())
            return -1;
        if(nums[x]==target)
            return x;
        return -1;
    }
};