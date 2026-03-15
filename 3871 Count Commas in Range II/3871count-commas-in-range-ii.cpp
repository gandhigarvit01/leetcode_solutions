class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if(n<1000) return 0;
        if(n<=999999){
            return ans += n-1000+1;
        }
        else ans += 999999-999;
        if(n<=999999999){
            return ans += 2*(n-1000000+1);
        }
        else ans += 2*(999999999-999999);
        if(n<=999999999999){
            return ans += 3*(n-1000000000+1);
        }
        else ans += 3*(999999999999-999999999);
        if(n<=999999999999999){
            return ans += 4*(n-1000000000000+1);
        }
        else ans += 4*(999999999999999-999999999999);
        return ans+5;
    }
};