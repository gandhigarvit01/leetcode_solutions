class Solution {
public: 
    bool mindays(vector<int>& bloomDay, int n, int k, int m, int mid){
        int c=0, a=0;
            for(int i=0; i<n; i++){
                if(bloomDay[i]<=mid){
                    a++;
                    if(a==k){
                        c++;
                        a=0;
                    }
                }
                else{
                    a=0;
                }
            }
        if(c>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k>(long long)n) return -1;
        int maxi = 0;
        for(int i=0; i<n; i++){
            if(bloomDay[i]>maxi){
                maxi = bloomDay[i];
            }
        }
        int l=1, r=maxi, mid=0, ans=-1;
        while(l<=r){
            mid = l+(r-l)/2;
            if(mindays(bloomDay,n,k,m,mid)){
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