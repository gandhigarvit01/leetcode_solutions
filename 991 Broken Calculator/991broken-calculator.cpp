class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int op = 0;
        while(target > startValue){
            if(target%2!=0){
                target++;
                op++;
            }
            else{
                target /= 2;
                op++;
            }
        }
        return op + (startValue-target);
    }
};