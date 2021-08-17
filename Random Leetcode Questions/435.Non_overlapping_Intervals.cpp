class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int cnt=0;
        int left=0;
        int right=1;
        while(right<intervals.size())
        {
            if(intervals[left][1]<=intervals[right][0])
            {
                left=right;
                right++;
            }
            else if(intervals[left][1]<intervals[right][1])
            {
                cnt++;
                right++;
            }
            else
            {
                cnt++;
                left=right;
                right++;
            }
        }
        return cnt;
    }
};