class Solution {
public:
    // bricks --2
    // ladders --1
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        for(int i=1;i<heights.size();i++)
        {
            int val=heights[i]-heights[i-1];
            if(val>0)
            {
                if(val<=bricks)
                {
                    pq.push(val);
                    bricks-=val;
                }
                else if(ladders!=0)
                {
                    if(pq.size()!=0 and pq.top()>val)
                    {
                        int p1=pq.top();
                        pq.pop();
                        pq.push(val);
                        bricks-=val;
                        bricks+=p1;
                    }
                    ladders--; 
                }
                else
                {
                    return i-1;
                }
            }
        }
        return heights.size()-1;
    }
};