class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
      int cnt=0;
      map<int,int>mp;
      for(int i=0;i<nums.size();i++)
          mp[nums[i]]++;
      for(auto x:mp)
      {
          if((!k and x.second>1)||(k and mp.count(x.first+k)))
              cnt++;
      }
      return cnt;
    }
};