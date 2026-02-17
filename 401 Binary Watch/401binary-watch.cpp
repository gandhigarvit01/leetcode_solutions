class Solution {
public:
    int count(int num){
        int ct = 0;
        for(int i=0; i<=5; i++){
            if((num & (1<<i))!=0) ct++;
        }
        return ct;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        if(turnedOn>=9) return {};
        for(int i=0; i<=11; i++){
            for(int j=0; j<=59; j++){
                if((count(i) + count(j))==turnedOn){
                    string time = "";
                    time = to_string(i);
                    time += ':';
                    if(j<10){
                        time += '0';
                    }
                    time += to_string(j);
                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};