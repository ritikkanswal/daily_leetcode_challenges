class Solution {
public:
    vector<int>sessions;
    map<string,int>dp;
    string encoding(int idx)
    {
        string res;
        vector<int>tmp=sessions;
        sort(tmp.begin(),tmp.end());
        res+=to_string(idx)+'?';
        for(int i=0;i<tmp.size();i++)
        {
            res+=to_string(tmp[i])+'?';
        }
        return res;
    }
    int fun(vector<int>& tasks, int &sessionTime,int i)
    {
        if(i>=tasks.size())
            return 0;
        string enc=encoding(i);
        if(dp.find(enc)!=dp.end())
            return dp[enc];
        // if we are thinking of adding into new session
        int ans;
        sessions.push_back(tasks[i]);
        ans=1+fun(tasks,sessionTime,i+1);
        sessions.pop_back();
        
        //second case for adding into any existing sessions
        
        for(int j=0;j<sessions.size();j++)
        {
            if((sessions[j]+tasks[i])<=sessionTime)
            {
                sessions[j]+=tasks[i];
                ans=min(ans,fun(tasks,sessionTime,i+1));
                sessions[j]-=tasks[i];
            }
        }
        
        return dp[enc]=ans;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        return fun(tasks,sessionTime,0);
    }
};