class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m=part.size();
        int n=s.size();
        size_t position = s.find(part);
        while(position != string::npos){
            s.erase(position,m);
            position = s.find(part);         
        }
        return s;
    }
};