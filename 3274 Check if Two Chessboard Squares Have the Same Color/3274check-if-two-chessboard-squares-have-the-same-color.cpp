class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int a=coordinate1[0]+coordinate1[1];
        int b=coordinate2[0]+coordinate2[1];

        if((b-a)%2==0)return true;
        else return false;
    }
};