// id:78705491
// runtime:8 ms
// memory:9.7 MB
// title:Final Prices With a Special Discount in a Shop
// translatedTitle:商品折扣后的最终价格
// questionId:1570
// time:2020-06-13 22:33:22

class Solution {
    static const int INF = 1e9;

  public:
    vector<int> finalPrices(vector<int> &prices) {
        vector<int> ret;
        for (int i = 0; i < (int)prices.size(); i++) {
            int ans = 0;
            for (int j = i + 1; j < (int)prices.size(); j++) {
                if (prices[j] <= prices[i]) {
                    ans = prices[j];
                    break;
                }
            }
            ret.push_back(prices[i]-ans);
        }
        return ret;
    }
};