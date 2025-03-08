class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int l = 1;
        int r = k;
        int mins = 0;
        for(int i=0; i<k; i++){
            if(blocks[i]=='W'){
                mins++;
            }
        }
        int mint = mins;
        while(r<n){
            if(blocks[r]!=blocks[l-1] && blocks[r]=='B'){
                mins--;
            }
            else if(blocks[r]!=blocks[l-1] && blocks[r]=='W'){
                mins++;
            }
            mint = min(mins, mint);
            r++;
            l++;
        }
        return mint;
    }
};