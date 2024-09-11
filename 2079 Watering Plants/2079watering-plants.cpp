class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        long int n=plants.size();
        long int steps=0;
        int i=0;
        int m=capacity;
        for(i=0; i<n; i++){
            if(capacity>=plants[i]){
                capacity=capacity-plants[i];
                steps++;


            }
            else{
                steps=steps+i+i;
                capacity=m;
                if(capacity>=plants[i]){
                capacity=capacity-plants[i];
                steps++;}

           

            }
        }
        return steps;
    }
};