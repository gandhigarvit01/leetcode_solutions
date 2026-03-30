class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        unordered_map<char,int> mpp;
        for(int i=0; i<n; i++){
            mpp[s[i]] = i;
        }
        int prev = -1;
        int i=0, j=mpp[s[i]];
        while(i<n){
            while(i<j){
                i++;
                j = max(j,mpp[s[i]]);
            }
            int length = j-prev;
            ans.push_back(length);
            prev = j;
            i++;
            j = max(j,mpp[s[i]]);
        }
        return ans;
    }
};