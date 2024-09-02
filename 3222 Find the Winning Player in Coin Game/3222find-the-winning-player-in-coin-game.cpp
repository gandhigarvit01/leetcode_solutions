class Solution {
public:
    string losingPlayer(int x, int y) {
        int c=0;
        while(x>=0 && y>=0){
            x=x-1;
            y=y-4;
            if(x>=0 && y>=0){
                c++;
            }

        }
        if(c%2==0){
            return "Bob";
        }
        else return "Alice";
    }
};