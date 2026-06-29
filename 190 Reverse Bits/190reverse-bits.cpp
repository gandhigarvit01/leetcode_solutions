class Solution {
public:
    int reverseBits(int n) {
        int l = 31, r = 0;
        while(l>r){
            int l_bit = (n>>l)&1;
            int r_bit = (n>>r)&1;
            if(l_bit != r_bit){
                n = n^(1<<l);
                n = n^(1<<r);
            }
            l--;
            r++;
        }
        return n;
    }
};