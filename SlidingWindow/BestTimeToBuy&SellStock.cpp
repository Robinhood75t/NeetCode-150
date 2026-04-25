class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int st = 0;
        int end = 1;
        int max_profit = 0;
        while(end < n){
            if(prices[st] < prices[end]){
                int profit = prices[end] - prices[st];
                max_profit = max(profit,max_profit);
            }
            else{
                st = end;
            }
            end++;
        }
        return max_profit;
    }
};
// approach 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = INT_MIN;
        int min_price = INT_MAX;
        for(int i = 0; i < n; i++){
            min_price = min(prices[i],min_price);
            int profit = prices[i] - min_price;
            max_profit = max(profit,max_profit);
        }
        return max_profit;
    }
};
// approach 3