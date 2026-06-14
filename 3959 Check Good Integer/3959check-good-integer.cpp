class Solution {
public:
    bool checkGoodInteger(int n) {
        int digsum = 0;
        int sqsum = 0;
        while(n>0){
            int rem = n%10;
            digsum += rem;
            sqsum += rem*rem;
            n = n/10;
        }
        if(sqsum - digsum >= 50) return true;
        return false;
    }
};