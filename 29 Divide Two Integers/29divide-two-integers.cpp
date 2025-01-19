class Solution {
public:
    int divide(int dividend, int divisor) {
         if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; 
        }
       
        long long m = abs((long long)dividend);
        long long n = abs((long long)divisor);
         long int k = 0;

        
        for(int i=31; i>=0; i--){
            if((n<<i)<=m){
                m= m-(n<<i);
                k=k|(1<<i);


   }
        }
      
       if ((dividend < 0) != (divisor < 0)) {
            k = -k;
        }
        return k;

    }
};