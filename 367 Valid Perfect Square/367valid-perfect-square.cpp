class Solution {
public:
    bool isPerfectSquare(int num) {
      int l=0;
      int r=num;
      long mid=l+(r-l)/2;
      while(l<=r){ 
      if(mid*mid>num){
        r=mid-1;
        mid=l+(r-l)/2;
      }  
      else if(mid*mid==num){
        return true;
      }
      else{
        l=mid+1;
        mid=l+(r-l)/2;
      }
      }
      return false;
    }
};