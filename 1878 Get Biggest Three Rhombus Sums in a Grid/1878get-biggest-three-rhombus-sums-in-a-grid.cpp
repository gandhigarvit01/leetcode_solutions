class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int a=0, b=0, c=0;
        int sum = 0;
        int m = grid.size();
        int n = grid[0].size();
        int rhombus_size = 1;
        int max_size = min(m,n);
        if(max_size%2==0) max_size--;
        max_size = (max_size+1)/2;
        while(rhombus_size<=max_size){
            for(int i=0; i<=m-(2*rhombus_size-1); i++){
                for(int j=rhombus_size-1; j<n-(rhombus_size-1); j++){
                    sum = 0;
                    int x=i, y=j;
                    sum += grid[x][y];
                    int l = rhombus_size-1;
                    int r = l;
                    while(r){
                        x++, y--;
                        sum += grid[x][y];
                        r--; 
                    }
                    r = l;
                    while(r){
                        x++, y++;
                        sum += grid[x][y];
                        r--;
                    }
                    r = l;
                    while(r){
                        x--, y++;
                        sum += grid[x][y];
                        r--;
                    }
                    r = l;
                    while(r){
                        x--, y--;
                        if(r!=1) sum += grid[x][y];
                        r--;
                    }
                    if(sum>c){
                        a = b;
                        b = c;
                        c = sum;
                    }
                    else if(sum>b && sum!=c){
                        a = b;
                        b = sum;
                    }
                    else if(sum>a && sum!=b && sum!=c){
                        a = sum;
                    }
                }
            }
            rhombus_size++;
        }
        vector<int> ans;
        if(c>0) ans.push_back(c);
        if(b>0) ans.push_back(b);
        if(a>0) ans.push_back(a);
        return ans;
    }
};