class Solution {
public:
    int mySqrt(int x) {
      int l=0;
      int r=x;
      long mid=l+(r-l)/2;
      long ans;


      while(l<=r){ 
      if(mid*mid>x){
        r=mid-1;
        mid=l+(r-l)/2;
      }  
      else if(mid*mid==x){
        ans=mid;
        return ans;
      }
      else{
        ans=mid;
        l=mid+1;
        mid=l+(r-l)/2;
      }
      }
return ans;
    }
};