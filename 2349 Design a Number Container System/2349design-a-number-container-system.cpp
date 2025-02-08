class NumberContainers {
    unordered_map<int,int> in;
    unordered_map<int,set<int>> ni;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(in.find(index)!=in.end()){
        int k = in[index];
        ni[k].erase(index);
        }
        in[index]=number;
        ni[number].insert(index);
    }
    
    int find(int number) {
        if(ni[number].size()>0){
            return *ni[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */