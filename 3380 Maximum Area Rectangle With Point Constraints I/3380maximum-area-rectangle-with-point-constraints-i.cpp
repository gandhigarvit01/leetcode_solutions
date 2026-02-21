class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int ans = -1;
        int n = points.size();
        map<pair<int,int>,int> mpp;
        for(auto& v : points){
            mpp[{v[0],v[1]}]++;
        }
        int x1,y1,x2,y2,x3,y3,x4,y4;
        for(int i=0; i<n-1; i++){
            x1 = points[i][0];
            y1 = points[i][1];
            for(int j=i+1; j<n; j++){
                x2 = points[j][0];
                y2 = points[j][1];
                if(x1==x2 || y1==y2) continue;
                x3 = x2, y3 = y1, x4 = x1, y4 = y2;
                if(mpp.find({x3,y3})!=mpp.end() && mpp.find({x4,y4})!=mpp.end()){
                    int inside = 0;
                    for(int i=0; i<n; i++){
                        int x = points[i][0];
                        int y = points[i][1];
                        if((x==x1 && y==y1) || (x==x2 && y==y2) || (x==x3 && y==y3) || (x==x4 && y==y4)) continue;
                        int s_x = min(x1,x2), l_x = max(x1,x2), s_y = min(y1,y2), l_y = max(y1,y2);
                        if(x>=s_x && x<=l_x && y>=s_y && y<=l_y) inside++;
                    }
                    if(inside>0) continue;
                    ans = max(ans, (x2-x1)*(y2-y1));
                }
            }
        }
        return ans;
    }
};