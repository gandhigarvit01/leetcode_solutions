class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n);
        vector<vector<int>> blue(n);
        for(vector<int> vec : redEdges){
            red[vec[0]].push_back(vec[1]);
        }
        for(vector<int> vec : blueEdges){
            blue[vec[0]].push_back(vec[1]);
        }
        vector<vector<bool>> visited(n,vector<bool>(2,false));
        vector<int> ans(n,-1);
        ans[0] = 0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        q.push({0,{1,0}});
        visited[0][1] = true;
        visited[0][0] = true;
// 0 -> last was blue, 1 ->last was red | (0,(0,0)) -> means node is 0, color is 0(blue) so next color should be red and dist is 0.
        while(!q.empty()){
            pair<int,pair<int,int>> p = q.front();
            q.pop();
            int node = p.first;
            int color = p.second.first;
            int dist = p.second.second;
            if(color==0){
                for(int v : red[node]){
                    if(!visited[v][1]){
                        visited[v][1] = true;
                        q.push({v,{1-color,dist+1}});
                        if(ans[v]==-1) ans[v] = dist+1;
                    }
                }
            }
            else if(color==1){
                for(int v : blue[node]){
                    if(!visited[v][0]){
                        visited[v][0] = true;
                        q.push({v,{1-color,dist+1}});
                        if(ans[v]==-1) ans[v] = dist+1;
                    }
                }
            }
        }
        return ans;
    }
};