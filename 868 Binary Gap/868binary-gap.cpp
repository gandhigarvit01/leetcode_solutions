class Solution {
public:
    int binaryGap(int n) {
        int gap = 0;
        int ans = 0;
        int setbits = 0;
        for(int i=0; i<32; i++){
            if((n & (1<<i))!=0){
                setbits++;
                ans = max(ans,gap);
                gap = 1;
            }
            else{
                if(setbits>0) gap++;
            }
        }
        if(setbits<=1) return 0;
        return ans;
    }
};