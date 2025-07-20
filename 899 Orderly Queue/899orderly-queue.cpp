class Solution {
public:
    string orderlyQueue(string s, int k) {
        string result = s;
        int n = s.size();
        vector<int> times(26,0);
        if(k==1){
            for(int i=0; i<n; i++){
                string temp = s.substr(i) + s.substr(0,i);
                result = min(result,temp);
            }
        }
        else{
            sort(result.begin(),result.end());
        }
        return result;
    }
};