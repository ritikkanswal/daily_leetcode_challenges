class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.size();i++)
        {
            if(!st.empty() and k>0 and st.top()>num[i])
            {
                st.pop();
                k--;
                i--;
            }
            else
            {
                st.push(num[i]);
            }
        }
        while(!st.empty() and k--)
        {
            st.pop();
        }
        string res;
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        string ans;
        int p=0;
        while(res[p]=='0')
            p++;
        for(int i=p;i<res.size();i++)
        {
            ans+=res[i];
        }
        if(ans=="")
            ans="0";
        return ans;
    }
};