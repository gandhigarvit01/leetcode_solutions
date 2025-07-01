class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n+1);
        ans[1] = 1;
        if(n==1) return 1;
        int i2,i3,i5;
        i2=i3=i5=1;
        for(int i=2; i<=n; i++){
            int k = ans[i2]*2;
            int l = ans[i3]*3;
            int m = ans[i5]*5;
            int minugly = min(min(k,l),m);
            ans[i] = minugly;
            if(k == minugly){
                i2++;
            }
            if(l == minugly){
                i3++;
            }
            if(m == minugly){
                i5++;
            }
        }
        return ans[n];
    }
};