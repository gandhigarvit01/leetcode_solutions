class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n=plants.size();
        int r1=0;
        int r2=0; 
        int c1=capacityA;
        int c2=capacityB;

        int i=0;
        int j=n-1;
        while(i<j){
            if(c1>=plants[i]){
                c1=c1-plants[i];
                i++;
            }
            else{
                r1++;
                c1=capacityA-plants[i];
                i++;
            }
            if(c2>=plants[j]){
                c2=c2-plants[j];
                j--;
            }
            else{
                r2++;
                c2=capacityB-plants[j];
                j--;
            }
        }
        if(i==j){
            if(c1>=c2 && c1<plants[i]){
                r1++;
            }
            else if(c2>c1 && c2<plants[j]){
                r2++;
            }
        }

        return r1+r2;


    }
};