class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count=0;
      
        for(int i=0; i<31; i++){
            if((num2 & (1<<i))!=0){
                count++;
            }
        }
        int k=0,j=0;
        for(int i=30; i>=0; i--){
            if(((num1 & (1<<i))!=0)&& count>0){
                k=k|1<<i;
                count--;
            }
        }
        if(count==0){
            return k;
        }
        else{
            while(count>0){
                if((num1 &(1<<j))==0){
                    count--;
                    k=k|1<<j;
                    j++;
                }
                else{
                    j++;
                }
            }
        }


return k;
    }
};