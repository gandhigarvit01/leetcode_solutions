class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        int mod = 1e9+7;
        int seats = 0;
        for(int i=0; i<n; i++){
            if(corridor[i]=='S') seats++;
        }
        if(seats%2!=0 || seats<2) return 0;
        long long ans = 1;
        int curr = 0;
        int curr_seats = 0;
        for(int i=0; i<n; i++){
            if(corridor[i]=='S') curr_seats++;
            if(curr_seats % 2 != 0){
                if(curr>0) ans = (ans*curr)%mod;
                curr = 0;
                continue;
            } 
            else if(curr_seats < seats && curr_seats != 0){
                curr++;
            }
        }
        return (int)ans;
    }
};