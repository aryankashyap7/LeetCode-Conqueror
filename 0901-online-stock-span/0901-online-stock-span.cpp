class StockSpanner {
public:
    stack<pair<int,int>> tmp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int curr=1;
        while(tmp.size()!=0 && tmp.top().first<=price)
        {
            curr+=tmp.top().second;
            tmp.pop();
        }
        tmp.push({price,curr});
        return tmp.top().second;
    }
};