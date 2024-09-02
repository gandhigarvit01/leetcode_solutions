class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink;
        int n= numBottles;
        int m= numExchange;
        int full;
        int empty;
        full= numBottles;
        empty= 0;

        drink= n;
        empty= n;
        full= 0;

        while(empty>=m){
            empty=empty-m;
            drink++;
            empty++;



        }
        return drink;

    }
};