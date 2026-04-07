class Robot {
public:
    int w,h;
    int x=0, y=0;
    char dir[4] = {'N','E','S','W'};
    int idx = 1;
    int peri = 0;
    Robot(int width, int height) {
        w = width;
        h = height;
        peri = 2*(w+h-2);
    }
    
    void step(int num) {
        int k = num % peri;
        if(k==0 && x==0 && y==0 && idx==1){
            idx = 2;
        }
        else{
        while(k){
            if(dir[idx]=='N'){
                if(y+1<h){
                    y++;
                    k--;
                }
                else{
                    idx--;
                    if(idx==-1) idx=3;
                }
            }
            else if(dir[idx]=='E'){
                if(x+1<w){
                    x++;
                    k--;
                }
                else{
                    idx--;
                    if(idx==-1) idx=3;
                }
            }
            else if(dir[idx]=='S'){
                if(y-1>=0){
                    y--;
                    k--;
                }
                else{
                    idx--;
                    if(idx==-1) idx=3;
                }
            }
            else{
                if(x-1>=0){
                    x--;
                    k--;
                }
                else{
                    idx--;
                    if(idx==-1) idx=3;
                }
            }
        }
    }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(dir[idx]=='N'){
            return "North";
        }
        else if(dir[idx]=='E'){
            return "East";
        }
        else if(dir[idx]=='S'){
            return "South";
        }
        else{
            return "West";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */