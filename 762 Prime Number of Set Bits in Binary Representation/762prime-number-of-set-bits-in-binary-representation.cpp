class Solution {
public:
    bool isprime(int n){
        if(n<=1) return false;
        if(n==2) return true;
        for(int i=2; i*i<=n; i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    bool binary(int n){
        int m = 0;
        for(int i=0; i<=22; i++){
            if((n & (1<<i))!=0) m++;
        }
        if(isprime(m)) return true;
        return false;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i=left; i<=right; i++){
            if(binary(i)) ans++;
        }
        return ans;
    }
};