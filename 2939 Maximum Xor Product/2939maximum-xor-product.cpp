class Solution {
public:
    int mod = 1e9+7;
    int maximumXorProduct(long long a, long long b, int n) {
        long long c = 0, d = 0;
        for(int i=50; i>=n; i--){
            if((a & (1LL<<i))!=0) c += 1LL<<i;
            if((b & (1LL<<i))!=0) d += 1LL<<i; 
        }
        for(int i=n-1; i>=0; i--){
            if((a & (1LL<<i)) == (b & (1LL<<i))){
                c += 1LL<<i;
                d += 1LL<<i;
            }
            else{
                if(c<d) c += 1LL<<i;
                else d += 1LL<<i;
            }
        }
        int ans = c % mod;
        ans = (ans * (d % mod)) % mod;
        return ans; 
    }
};