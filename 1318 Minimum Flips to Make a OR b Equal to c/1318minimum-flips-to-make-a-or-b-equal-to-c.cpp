class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for(int i=0; i<32; i++){
            int bit1 = (a & (1<<i))==0?0:1;
            int bit2 = (b & (1<<i))==0?0:1;
            int bit3 = (c & (1<<i))==0?0:1;
            if((bit1 | bit2) != bit3){
                if(bit3==0 && bit1==bit2) flips += 2;
                else flips++;
            }
        }
        return flips;
    }
};