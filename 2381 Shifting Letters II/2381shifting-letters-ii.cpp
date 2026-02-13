class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> vec(n,0);
        for(auto &v : shifts){
            int start = v[0];
            int end = v[1]+1;
            int val = v[2]==0?-1:1;
            vec[start] += val;
            if(end<n){
                vec[end] -= val;
            }
        }
        for(int i=1; i<n; i++){
            vec[i] += vec[i-1];
        }
        for(int i=0; i<n; i++){
            int pos = s[i]-'a';
            int new_pos = ((((pos + vec[i]) % 26) + 26) %26);
            s[i] = 'a' + new_pos;
        }
        return s;
    }
};