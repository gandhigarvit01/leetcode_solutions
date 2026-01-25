class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> st(bank.begin(),bank.end());
        int n = bank.size();
        if(st.find(startGene)!=st.end()){
            st.erase(startGene);
        }
        int ans = 0;
        queue<string> q;
        char ch[4] = {'A','C','G','T'};
        q.push(startGene);
        q.push("NULL");
        while(!q.empty()){
            string s = q.front();
            q.pop();
            if(s==endGene){
                return ans;
            }
            if(s=="NULL"){
                if(!q.empty()){
                    ans++;
                    q.push("NULL");
                }
            }
            else{
                for(int i=0; i<8; i++){
                    string t = s;
                    for(int j=0; j<4; j++){
                        if(t[i]!=ch[j]){
                            t[i] = ch[j];
                            if(st.find(t)!=st.end()){
                                q.push(t);
                                st.erase(t);
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};