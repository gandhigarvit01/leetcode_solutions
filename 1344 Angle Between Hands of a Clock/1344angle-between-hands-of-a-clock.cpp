class Solution {
public:
    double angleClock(int hour, int minutes) {
        double total_hrs = hour + (minutes/60.0);
        double deg_by_hr = (total_hrs)*(30.0);
        double deg_by_min = (minutes)*(6.0);
        double diff =  abs(deg_by_hr - deg_by_min);
        return min(diff,360.0-diff);
    }
};