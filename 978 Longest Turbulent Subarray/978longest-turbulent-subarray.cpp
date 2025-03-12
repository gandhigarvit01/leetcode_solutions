class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int c=0, maxi=0, r=0;
        while(r<n-1){
            if((r%2==0 && arr[r]<arr[r+1]) || (r%2!=0 && arr[r]>arr[r+1])){
                c++;
                maxi = max(maxi,c);
            }
            else{
                c = 0;
            }
            r++;
        } 
        r = 0;
        c = 0;
        while(r<n-1){
             if((r%2==0 && arr[r]>arr[r+1]) || (r%2!=0 && arr[r]<arr[r+1])){
                c++;
                maxi = max(maxi,c);
            }
            else{
                c = 0;
            }
            r++;
        }
        return maxi+1;
    }
};