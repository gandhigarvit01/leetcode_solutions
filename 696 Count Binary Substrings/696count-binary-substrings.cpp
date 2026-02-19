class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        vector<int> vec;
        int ones = 0;
        int zeros = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                if(ones!=0){
                    vec.push_back(ones);
                    ones = 0;
                }
                zeros++;
            }
            else{
                if(zeros!=0){
                    vec.push_back(zeros);
                    zeros = 0;
                }
                ones++;
            }
        }
        int k = max(ones,zeros);
        vec.push_back(k);
        int m = vec.size();
        int count = 0;
        for(int i=0; i<m-1; i++){
            count += min(vec[i],vec[i+1]);
        }
        return count;
    }
};