class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a=(ax2-ax1)*(ay2-ay1);
        int b=(bx2-bx1)*(by2-by1);
        int j=0,k=0,l=0,m=0,n=0;
        if(!(bx1>=ax2 || ax1>=bx2)){
            j = min(ax2,bx2)-max(ax1,bx1);}
        if(!(by1>=ay2 || ay1>=by2)){
            k = min(ay2,by2)-max(ay1,by1);}
        return (a+b)-(j*k);
    }
};