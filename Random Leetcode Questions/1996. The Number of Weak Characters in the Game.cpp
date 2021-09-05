class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        int cnt=0;
        int n=p.size();
        int Ma[n];
        int ma=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            ma=max(ma,p[i][1]);
            Ma[i]=ma;
        }
        int i=0;
        while(i<n-1)
        {
            int j=i+1;
            while(j<n and p[i][0]==p[j][0])
                j++;
            if(p[i][1]!=-1 and j<n and p[i][1]<Ma[j])
            {
                p[i][1]=-1;
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};