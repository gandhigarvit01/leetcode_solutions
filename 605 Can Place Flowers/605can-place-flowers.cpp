class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m= flowerbed.size();
        
        if(m==1){
            if(flowerbed[m-1]==0){
                flowerbed[m-1]=1;
                n--;
            }
        }



        for(int i=0; i<m; i++){
            if((i==0) && (flowerbed[i]==0) && (flowerbed[i+1]==0)){
                flowerbed[0]=1;
                n--;
            }
            else if((i!=0 && i!=m-1) && (flowerbed[i]==0) && (flowerbed[i-1]==0) && (flowerbed[i+1]==0)){
                flowerbed[i]=1;
                n--;
            }
            else if((i==m-1) && (flowerbed[m-1]==0) && (flowerbed[m-2]==0)){
                flowerbed[m-1]=1;
                n--;
            }

        }
        if(n<=0){return true;}
        else {return false;}
    }
};