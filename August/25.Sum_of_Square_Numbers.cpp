class Solution {
public:
    bool isSquare(int x)
    {
        int y=sqrt(x);
        return y*y==x;
    }
    bool judgeSquareSum(int c) {
        for(int i=0;i<=sqrt(c);i++)
        {
            int a=i*i;
            int b=c-a;
            if(b>=0 and isSquare(b))
                return true;
        }
        return false;
    }
};