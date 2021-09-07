class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int ma=-1;
        char res;
        for(int i=0;i<releaseTimes.size();i++)
        {
            int ch;
            if(i==0)
                ch=releaseTimes[i];
            else
                ch=(releaseTimes[i]-releaseTimes[i-1]);
            if(ch>ma)
            {
                
                ma=ch;
                res=keysPressed[i];
            }
            else if(ch==ma)
            {
                res=max(res,keysPressed[i]);
            }
        }
        return res;
    }
};