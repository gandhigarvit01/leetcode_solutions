class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right) return left;
        int num = 0;
        long long range = (long long)right - (long long)left + 1;
        for(int i=0; i<32; i++){
            int consecutive_no = 1<<i;
            if(consecutive_no >= range){
                int l_bit = (left>>i)&1;
                int r_bit = (right>>i)&1;
                if(l_bit==r_bit && l_bit==1){
                    num |= 1<<i;
                }
            }
        }
        return num;
    }
};