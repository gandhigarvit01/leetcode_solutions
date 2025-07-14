class Solution {
public:
    int mod = 1e9+7;
    int minimumPossibleSum(int n, int target) {
        long long k = target/2;
        long long m = target;
        long long N = n;
        if(n<=k){
            return ((N*(N+1))/2)%mod;
        }
        else{
            long long a = (k*(k+1))/2;
            long long b = (m*(m-1))/2;
            long long r = (n-k+m-1);
            long long c = (r*(r+1))/2;

            return (a+c-b)%mod;
        }
        return 0;
    }
};