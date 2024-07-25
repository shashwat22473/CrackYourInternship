class StockSpanner {
public:
    stack<pair<int,int>> st;
    int count_;
    StockSpanner() {
        count_=0;
        st.push({1000000000,0});
    }
    
    int next(int price) {
        count_++;
        while(st.top().first<=price){st.pop();}
        int ans=count_-st.top().second;
        st.push({price,count_});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
