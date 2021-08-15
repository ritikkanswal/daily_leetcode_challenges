class Solution {
public:
    int dist(vector<int>& p1, vector<int>& p2)
    {
        return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int>s;
        s.insert({dist(p1,p2),dist(p1,p3),dist(p1,p4),dist(p3,p4),dist(p4,p2),dist(p2,p3)});
        return !s.count(0) and s.size()==2;
    }
};