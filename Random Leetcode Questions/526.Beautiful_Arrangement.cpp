class Solution {
public:
    int cnt=0;
    void permute(int n,vector<bool>visited,int val)
    {
        if(val==n)
        {
            cnt++;
            return;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(visited[i]) continue;
            visited[i]=1;

            if(i%(val+1)!=0 and (val+1)%i!=0)
            {
                visited[i]=0;
                continue;
            }
            permute(n,visited,val+1);
            visited[i]=0;
        }
    }
    int countArrangement(int n) {
        vector<bool>visited(n+1);
        permute(n,visited,1);
        return cnt;
    }
};