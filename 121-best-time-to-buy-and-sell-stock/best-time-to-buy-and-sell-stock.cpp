class Solution {
public:
    //Recursive logic
    // int bestBuy(int best, int i, vector<int>& prices) {
    //     if(i == prices.size()) return 0;

    //     int currProfit = 0;
    //     int nextProfit = 0;

    //     if(i == 0) currProfit = INT_MIN;
    //     if(i > 0) {
    //         if(prices[i-1] > best) {
    //             currProfit = prices[i] - best;
    //             nextProfit = bestBuy(best, i+1, prices);
    //         } else if (prices[i-1] < best){
    //             currProfit = prices[i] - prices[i-1];
    //             nextProfit = bestBuy(prices[i-1], i+1, prices);
    //         }  else {
    //             currProfit = prices[i] - best;
    //             nextProfit = bestBuy(best, i+1, prices);
    //         }
    //     } else {
    //         nextProfit = bestBuy(prices[i], i+1, prices);
    //     }
    //     return max(currProfit, nextProfit);
    // }

    int maxProfit(vector<int>& prices) {
        //return bestBuy(INT_MAX, 0, prices);
        int n = prices.size();
        if(n == 1) return 0;

        int bestBuy = INT_MAX, maxProfit = 0;
        
        for(int i = 1; i < n; i++) {
            if(bestBuy < prices[i-1]) {
                int currProfit = prices[i] - bestBuy;
                maxProfit = max(currProfit, maxProfit);

            } else {
                bestBuy = prices[i-1];
                int currProfit = prices[i] - bestBuy;
                maxProfit = max(currProfit, maxProfit);
            }
        }

        return maxProfit;
    }
};