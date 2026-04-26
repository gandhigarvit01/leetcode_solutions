class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<pair<int,int>> vec(5, pair<int,int>(0,0));
        for(int i=0; i<n; i++){
            if(s[i]=='a'){
                if(vec[0].first==0){
                    vec[0].second = i;
                }
                vec[0].first++;
            }
            if(s[i]=='e'){
                if(vec[1].first==0){
                    vec[1].second = i;
                }
                vec[1].first++;
            }
            if(s[i]=='i'){
                if(vec[2].first==0){
                    vec[2].second = i;
                }
                vec[2].first++;
            }
            if(s[i]=='o'){
                if(vec[3].first==0){
                    vec[3].second = i;
                }
                vec[3].first++;
            }
            if(s[i]=='u'){
                if(vec[4].first==0){
                    vec[4].second = i;
                }
                vec[4].first++;
            }
        }
        vector<tuple<int,int,char>> vowel;
        vowel.push_back({vec[0].first,vec[0].second,'a'});
        vowel.push_back({vec[1].first,vec[1].second,'e'});
        vowel.push_back({vec[2].first,vec[2].second,'i'});
        vowel.push_back({vec[3].first,vec[3].second,'o'});
        vowel.push_back({vec[4].first,vec[4].second,'u'});

        sort(vowel.begin(), vowel.end(), [](auto &a, auto &b) {
            if(get<0>(a) != get<0>(b)) 
                return get<0>(a) > get<0>(b);
    
            return get<1>(a) < get<1>(b); 
        });
        string t = "";
        for(int i=0; i<5; i++){
            char ch = get<2>(vowel[i]);
            int val = get<0>(vowel[i]);
            t = t + string(val,ch);
        }
        int l = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                s[i] = t[l];
                l++;
            }
        }
        return s;
    }
};