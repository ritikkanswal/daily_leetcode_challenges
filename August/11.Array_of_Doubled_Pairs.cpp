class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int zero=0;
        unordered_map<int,int>present;
        for(int i=0;i<arr.size();i++)
            arr[i]==0?zero++:present[arr[i]]++;
        
        if(zero & 1) return 0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]!=0)
            {
                if (present[arr[i]] && present[2 * arr[i]])
                {
                    present[arr[i]]-=1;
                    present[2 * arr[i]]-=1;
                }
            }
        }
        for(auto i:present) 
            if(i.second>=1) return 0;
        return 1;
    }
};