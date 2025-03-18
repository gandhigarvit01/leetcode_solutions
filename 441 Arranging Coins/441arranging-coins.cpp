class Solution {
public:
    int arrangeCoins(int n) {
        int l=1;
        int r=n;
        int mid=0;
        long long ans=0, m=0;
        while(l<=r){
            mid = l+(r-l)/2;
            m = ((long long)mid*(long long)(mid+1))/2;
            if(m>n){
                r = mid-1;
            }
            else{
                ans = mid;
                l = mid+1;
            }
        }
        return ans;
    }
};