// id:369163564
// runtime:0 ms
// memory:5.8 MB
// title:Number of Common Factors
// translatedTitle:公因子的数目
// questionId:2507
// time:2022-10-02 10:30:39


class Solution {
  public:
    int commonFactors(int a, int b) {
        int ans = 0;
        for (int i = 1; i <= 1000; i++) {
            if (a % i == 0 && b % i == 0)
                ans++;
        }
        return ans;
    }
};