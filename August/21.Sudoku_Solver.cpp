class Solution {
public:
    vector<vector<char>>res;
    bool isValid(vector<vector<char>>& board,int i,int j,int k)
    {
        for(int l=0;l<9;l++)
        {
            if(board[i][l]==k+'0')
                return false;
        }
        
        for(int l=0;l<9;l++)
        {
            if(board[l][j]==k+'0')
                return false;
        }
        int x=(i/3)*3;
        int y=(j/3)*3;
        for(int l=0;l<3;l++)
        {
            for(int m=0;m<3;m++)
            {
                if(board[x+l][y+m]==k+'0')
                    return false;
            }
        }
        
        return true;
    }
    void fun(vector<vector<char>>& board,int i,int j)
    {
        if(i==9)
        {
            res=board;
            return;
        }
        int ni=0,nj=0;
        if(j==8)
        {
            ni=i+1;
            nj=0;
        }
        else
        {
            ni=i;
            nj=j+1;
        }
        if(board[i][j]!='.')
        {
            fun(board,ni,nj);
        }
        else
        {
            for(int k=1;k<=9;k++)
            {
                if(isValid(board,i,j,k))
                {
                    board[i][j]=k+'0';
                    fun(board,ni,nj);
                    board[i][j]='.';
                } 
            } 
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        fun(board,0,0);
        board=res;
    }
};