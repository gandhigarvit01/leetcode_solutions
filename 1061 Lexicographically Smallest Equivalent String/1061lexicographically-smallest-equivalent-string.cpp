class Solution {
public:
    int find(int i, vector<int>& parent){
        if(parent[i]==i){
            return i;
        }
        return parent[i] = find(parent[i],parent);
    }
    void unite(int i, int j, vector<int>& parent, vector<int>& rnk){
        int p1 = find(i,parent);
        int p2 = find(j,parent);

        if(p1==p2) return;
        else{
            if(rnk[p1]<rnk[p2]){
                parent[p2] = p1;
            }
            else{
                parent[p1] = p2;
            }
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> rnk(26);
        vector<int> parent(26);
        for(int i=0; i<26; i++){
            rnk[i] = i;
            parent[i] = i;
        }
        int n = s1.size();
        for(int i=0; i<n; i++){
            if(find(s1[i]-'a',parent)!=find(s2[i]-'a',parent)){
                unite(s1[i]-'a',s2[i]-'a',parent,rnk);
            }
        }
        int m = baseStr.size();
        for(int i=0; i<m; i++){
            int baap = find(baseStr[i]-'a',parent);
            char c = baap + 'a';
            baseStr[i] = c;
        }
        return baseStr;
    }
};