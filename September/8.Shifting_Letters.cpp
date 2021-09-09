class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
        long long tmp=0,sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=shifts[i];
        }
        for(int i=0;i<n;i++)
        {
            s[i]=((s[i]-'a'+(sum%26))%26)+'a';
            sum-=shifts[i];
        }
        return s;
    }
};