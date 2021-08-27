class Solution {
public:
    bool isValidSerialization(string preorder) {
        int capacity=1;
        preorder+=',';
        for(int i=0;i<preorder.size();i++)
        {
            if(preorder[i]!=',') continue;
            capacity--;
            if(capacity<0) return 0;
            if(preorder[i-1]!='#')
                capacity+=2;
        }
        return capacity==0;
    }
};