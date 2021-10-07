class Solution {
public:
    bool fun(vector<vector<char>>& board, string &word,int count,int i,int j) 
    {
        if(count==word.size()) return 1;
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[count]) return 0;
        bool l1=0,l2=0,l3=0,l4=0;
        char tmp=board[i][j];
        board[i][j]='?';
        l1=fun(board,word,count+1,i+1,j);
        l2=fun(board,word,count+1,i,j+1);
        l3=fun(board,word,count+1,i-1,j);
        l4=fun(board,word,count+1,i,j-1);
        board[i][j]=tmp;
        return (l1 or l2 or l3 or l4); 
    }
    bool exist(vector<vector<char>>& board, string &word) 
    {
        int r=board.size();
        int c=board[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
               if(fun(board,word,0,i,j))
                   return 1;
            }
        }
        return 0;
    }
};