class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        map<string,int>mp;
        string res="";
        for(int i=0;i<nums.size();i++)
        {
            res+='0';
            mp[nums[i]]++;
        }
        int n=nums.size();
        int i=0,x=0;
        while(i<=n+1)
        {
            if(!mp[res])
                return res;
            res[i]='1';
            i++;
        }
        return "";
    }
};