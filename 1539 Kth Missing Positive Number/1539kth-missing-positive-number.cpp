class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l=0, r=n-1, mid=0, ans=0;
        while(l<=r){
            mid = l+(r-l)/2;
            if(arr[mid]-mid-1<k){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        if(r<0) return k;
        int m = k-(arr[r]-r-1);
        return arr[r]+m;
    }
};