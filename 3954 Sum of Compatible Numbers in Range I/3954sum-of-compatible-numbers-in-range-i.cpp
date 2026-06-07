class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans = 0;
        for(int i=n-k; i<=n+k; i++){
            if(i>=0 && ((i & n)==0)) ans += i;
        }
        return ans;
    }
};