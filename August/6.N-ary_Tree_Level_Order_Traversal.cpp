/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void helper(Node* root,vector<vector<int>> &res)
    {
        if(!root) return;
        queue<Node *>q;
        q.push(root);
        while(!q.empty())
        {
            int cnt=q.size();
            vector<int>v;
            for(int i=0;i<cnt;i++)
            {
                Node *curr=q.front();
                q.pop();
                v.push_back(curr->val);
                int sz=curr->children.size();
                for(auto x:curr->children)
                {
                    if(x)
                        q.push(x);
                }
            }
            res.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        helper(root,res);
        return res;
    }
};