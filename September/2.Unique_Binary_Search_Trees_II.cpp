class Solution {
public:
    vector<TreeNode*> Solve(int start,int end) {
        vector<TreeNode*> v;
        if(start > end) {
            v.push_back(NULL);
            return v;
        }
        for(int i = start; i <= end; i++){
            auto left = Solve(start,i-1);
            auto right = Solve(i+1,end);
            for(auto l : left) {
                for(auto r : right){
                    TreeNode* NewNode = new TreeNode(i, l, r);
                    v.push_back(NewNode);
                }
            }
        }
        return v;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) 
            return vector<TreeNode*>();
        auto ans = Solve(1,n);
        return ans;
    }
};