class Solution {
public:
    int n;
    string ans = "";
    void solve(string& s, int i, set<string>& st){
        if(i==n){
            if(st.find(s)==st.end()){
                ans = s;
            }
            return;
        }
        s.push_back('1');
        solve(s,i+1,st);
        s.pop_back();
        s.push_back('0');
        solve(s,i+1,st);
        s.pop_back();
        return;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        set<string> st(nums.begin(),nums.end());
        string s = ""; 
        solve(s,0,st);
        return ans;
    }
};