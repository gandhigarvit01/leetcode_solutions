class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()){
            i++;
            st.push({price,i});
            return i; 
        }
        else{
            while(!st.empty() && st.top().first<=price){
                st.pop();
            }
            if(!st.empty()){
            int a = st.top().second;
            i++;
            st.push({price,i});
            return i-a;
            }
            else{
                i++;
                st.push({price,i});
                return i;
            }
        }
        return 0;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */