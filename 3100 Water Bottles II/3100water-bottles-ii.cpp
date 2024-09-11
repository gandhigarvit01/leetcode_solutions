class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int fb = numBottles;
        int eb =0;
        int db =0;

        db=numBottles;
        eb=numBottles;
        fb=0;

        while(eb>=numExchange){
            eb=eb-numExchange;
            db++;
            eb++;
            numExchange++;
        }
        return db;
    }
};