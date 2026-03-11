class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0;
        int idx = 0;
        for(int i=0; i<32; i++){
            if((n & (1<<i))!=0){
                idx = i;
            }
        }
        for(int i=0; i<=idx; i++){
            if((n & (1<<i))==0){
                ans += (1<<i);
            }
        }
        return ans;
    }
};