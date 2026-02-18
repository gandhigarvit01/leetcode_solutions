class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        int k = 0;
        for(int i=0; i<=31; i++){
            if((n & (1<<i))!=0) k=i;
        }
        for(int i=0; i<=k; i++){
            if((n & (1<<i))==0){
                if(prev==0) return false;
                prev = 0;
            }
            else if((n & (1<<i))!=0){
                if(prev==1) return false;
                prev = 1;
            }
        }
        return true;
    }
};