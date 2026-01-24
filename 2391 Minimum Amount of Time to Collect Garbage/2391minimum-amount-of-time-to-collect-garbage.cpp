class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int ans = 0;
        int G = 0, P = 0, M = 0;
        int Gin = -1, Pin = -1, Min = -1; 
        for(int i=0; i<n; i++){
            int m = garbage[i].size();
            for(int j=0; j<m; j++){
                if(garbage[i][j]=='G'){
                    G++;
                    Gin = i;
                }
                else if(garbage[i][j]=='P'){
                    P++;
                    Pin = i;
                }
                else{
                    M++;
                    Min = i;
                }
            }
        }
        // calculate G-
        ans += G;
        for(int i=0; i<Gin; i++){
            ans += travel[i];
        }
        // calc. p-
        ans += P;
        for(int i=0; i<Pin; i++){
            ans += travel[i];
        }
        // calc M-
        ans += M;
        for(int i=0; i<Min; i++){
            ans += travel[i];
        }
        return ans;
    }
};