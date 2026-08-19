class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 2*n;
        int m = reservedSeats.size();
        sort(reservedSeats.begin(), reservedSeats.end());
        int prev_row = -1;
        bool g1 = true, g2 = true, g3 = true;
        for(int i=0; i<m; i++){
            int row = reservedSeats[i][0]-1;
            int seat = reservedSeats[i][1]-1;
            if(row != prev_row){
                // evaluate prev_row
                if(g1==false) ans -= 1;
                if(g3==false) ans -= 1;
                if(g1==false && g3==false && g2==true) ans += 1;
                // update
                prev_row = row;
                g1 = true, g2 = true, g3 = true;
            }
            if(seat==1 || seat==2){
                g1 = false;
            }
            else if(seat==3 || seat==4){
                g1 = false;
                g2 = false;
            }
            else if(seat==5 || seat==6){
                g2 = false;
                g3 = false;
            }
            else if(seat==7 || seat==8){
                g3 = false;
            }
        }
        if(g1==false) ans -= 1;
        if(g3==false) ans -= 1;
        if(g1==false && g3==false && g2==true) ans += 1;
        return ans;
    }
};