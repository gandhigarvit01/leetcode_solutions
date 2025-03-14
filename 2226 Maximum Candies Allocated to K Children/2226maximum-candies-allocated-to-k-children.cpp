class Solution {
public:
    bool maxcan(int m, vector<int>& candies, int j, long long a){
        long long c = 0;
        for(int i=0; i<j; i++){
            c += candies[i]/m;
        }
        if(c>=a) return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int x = 0;
        for(int i=0; i<n; i++){
            if(candies[i]>x){
                x = candies[i];
            }
        }
        int mid=0, l=1, r=x, ans=0;
        while(l<=r){
            mid = l+(r-l)/2;
            if(maxcan(mid, candies, n, k)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};