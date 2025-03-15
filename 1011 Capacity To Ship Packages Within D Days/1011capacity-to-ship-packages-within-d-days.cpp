class Solution {
public:
    bool swd(vector<int>& weights, int n, int days, int m){
       int c=1, total=0;
        for(int i=0; i<n; i++){
            if(total + weights[i] <= m){
                total += weights[i];
            }
            else{
                total = 0;
                total += weights[i];
                c++;
            }
        }
        if(c<=days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0, maxi=0;
        for(int i=0; i<n; i++){
            sum += weights[i];
            if(weights[i]>maxi){
                maxi = weights[i];
            }
        }
        int l=maxi;
        int r=sum;
        int mid=0;
        int ans=0;
        while(l<=r){
            mid = l+(r-l)/2;
            if(swd(weights,n,days,mid)){
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return ans;          
    }
};