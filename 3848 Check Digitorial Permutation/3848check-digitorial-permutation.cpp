class Solution {
public:
    int ans = 0;
    bool isDigitorialPermutation(int n) {
        vector<int> fact(10,0);
        vector<int> vec1(10,0);
        vector<int> vec2(10,0);
        fact[0] = 1;
        fact[1] = 1;
        for(int i=2; i<10; i++){
            fact[i] = i*fact[i-1];
        }
        int m = n;
        while(m>0){
            int temp = m % 10;
            ans += fact[temp];
            vec1[temp]++;
            m = m/10;
        }
        while(ans>0){
            int t = ans % 10;
            vec2[t]++;
            ans = ans/10;
        }
        for(int i=0; i<10; i++){
            if(vec1[i]!=vec2[i]) return false;
        }
        return true;
    }
};