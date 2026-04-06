class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        char dir[] = {'N','E','S','W'};
        int n = commands.size();
        int ans = 0;
        set<pair<int,int>> st;
        int m = obstacles.size();
        for(int i=0; i<m; i++){
            st.insert({obstacles[i][0],obstacles[i][1]});
        }
        int idx = 0;
        int x=0, y=0;
        for(int i=0; i<n; i++){
            if(commands[i]==-1){
                idx++;
                if(idx==4) idx = 0;
            }
            else if(commands[i]==-2){
                idx--;
                if(idx==-1) idx = 3;
            }
            else{
                int k = commands[i];
                if(dir[idx]=='N'){
                    while(k--){
                        if(st.find({x,y+1})==st.end()){
                            y++;
                            ans = max(ans, x*x + y*y);
                        }
                        else{
                            break;
                        }
                    }
                }
                else if(dir[idx]=='E'){
                    while(k--){
                        if(st.find({x+1,y})==st.end()){
                            x++;
                            ans = max(ans, x*x + y*y);
                        }
                        else{
                            break;
                        }
                    }
                }
                else if(dir[idx]=='S'){
                    while(k--){
                        if(st.find({x,y-1})==st.end()){
                            y--;
                            ans = max(ans, x*x + y*y);
                        }
                        else{
                            break;
                        }
                    }
                }
                else{
                    while(k--){
                        if(st.find({x-1,y})==st.end()){
                            x--;
                            ans = max(ans, x*x + y*y);
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};