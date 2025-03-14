class Solution {
public:
    bool mis(vector<int>& piles, int n, int h, int m){
        long long  c = 0;
        for(int i=0; i<n; i++){
            if(piles[i]%m==0){
                c += piles[i]/m;
            }
            else{
                c += piles[i]/m+1;
            }
        }
        if(c>h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = 0;
        for(int i=0; i<n; i++){
            if(piles[i]>maxi){
                maxi = piles[i];
            }
        }
        int l=1, r=maxi, mid=0, ans=0;
        while(l<=r){
            mid = l+(r-l)/2;
            if(mis(piles,n,h,mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};