class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int ans = 0;
        int du[4] = {0,-1,0,1};
        int dv[4] = {-1,0,1,0};
        queue<pair<int,int>> q;
        visited[entrance[0]][entrance[1]] = true;
        q.push({entrance[0],entrance[1]});
        q.push({-1,-1});
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int u = p.first;
            int v = p.second;
            if(u==0 || u==m-1 || v==0 || v==n-1){
                if(!(u==entrance[0] && v==entrance[1])){
                    return ans;
                }
            }
            if(u==-1){
                if(!q.empty()){
                    ans++;
                    q.push({-1,-1});
                }
            }
            else{
                for(int i=0; i<4; i++){
                    if(u+du[i]>=0 && u+du[i]<m && v+dv[i]>=0 && v+dv[i]<n){
                        if(maze[u+du[i]][v+dv[i]]=='.' && visited[u+du[i]][v+dv[i]]==false){
                        q.push({u+du[i],v+dv[i]});
                        visited[u+du[i]][v+dv[i]] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};