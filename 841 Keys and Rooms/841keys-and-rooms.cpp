class Solution {
public:
    int n;
    void findrooms(int u,vector<vector<int>>& rooms, vector<bool>& visited){
        visited[u] = true;
        for(auto v : rooms[u]){
            if(!visited[v]){
                findrooms(v,rooms,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        vector<bool> visited(n,false);

        findrooms(0,rooms,visited);

        for(int i=0; i<n; i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};