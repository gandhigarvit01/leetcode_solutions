class Solution {
public:
    bool isprime(int n){
        if(n==1) return false;
        for(int j=2; j*j<=n; j++){
            if(n%j==0) return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int ans = 0;
        int r = 0, m = n;
        while(m>0){
            int rem = m%10;
            m = m/10;
            r = r*10 + rem;
        }
        for(int i=min(n,r); i<=max(n,r); i++){
            if(isprime(i)) ans += i;
        }
        return ans;
    }
};