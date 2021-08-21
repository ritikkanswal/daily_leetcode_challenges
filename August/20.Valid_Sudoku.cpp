class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r=9;
        int c=9;
        //case 1 for rows
        for(int i=0;i<r;i++)
        {
            map<char,int>mp;
            for(int j=0;j<c;j++)
            {
                if(board[i][j]!='.')
                {
                    if(mp[board[i][j]])
                        return false;
                    mp[board[i][j]]++;
                }
            }
        }
        //case 2 for col
         for(int i=0;i<c;i++)
        {
            map<char,int>mp;
            for(int j=0;j<r;j++)
            {
                if(board[j][i]!='.')
                {
                    if(mp[board[j][i]])
                        return false;
                    mp[board[j][i]]++;
                }
            }
        }
        
        //case 3 for 3X3 matrix
        int i=0,j=0;
        
        while(i<9 and j<9)
        {
             map<char,int>mp;
            for(int m=i;m<i+3;m++)
            {
                for(int n=j;n<j+3;n++)
                {
                     if(board[m][n]!='.')
                     {
                        if(mp[board[m][n]])
                            return false;
                        mp[board[m][n]]++;
                     }
                }
            }
            if(j+3==9)
            {
                if(i+3==9)
                    break;
                else
                {
                    i+=3;
                    j=0;
                }
            }
            else
                j+=3;
        }
        return true;
    }
};