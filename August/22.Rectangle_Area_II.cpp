class Solution {
public:
    #define ll long long
    #define mod 1000000007
    int rectangleArea(vector<vector<int>>& rectangles) {
        ll res = 0;
        set<int> x,y;
        for(auto v:rectangles){
            x.insert(v[0]);x.insert(v[2]);
            y.insert(v[1]);y.insert(v[3]);
        }
        vector<int> Cx(x.begin(),x.end());
        vector<int> Cy(y.begin(),y.end());
        vector<vector<bool>> Visited(x.size(),vector<bool>(y.size(),false));
        for(auto v:rectangles){
            for(auto start_x=lower_bound(Cx.begin(),Cx.end(),v[0]);*start_x!=v[2];start_x++){
                for(auto start_y=lower_bound(Cy.begin(),Cy.end(),v[1]);*start_y!=v[3];start_y++){
                    int i = start_x - Cx.begin();
                    int j = start_y - Cy.begin();
                    if(!Visited[i][j]){
                        ll Wi = *next(start_x) - *start_x;
                        ll Hi = *next(start_y) - *start_y;
                        res = (res + (Wi*Hi)%mod)%mod;
                    }
                    Visited[i][j] = 1;
                }
            }
        }
        return res;
    }
};