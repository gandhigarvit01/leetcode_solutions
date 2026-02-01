class Solution {
public:
    int countMonobit(int n) {
        int idx = -1;
        int setbits = 0;
        for(int i=0; i<=10; i++){
            if((n & (1<<i))!=0){
                idx = i;
                setbits++;
            }
        }
        int ans = 1;
        ans += idx;
        if(setbits==idx+1){
            ans += 1;
        }
        return ans;
    }
};