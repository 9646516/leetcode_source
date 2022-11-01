// id:373639020
// runtime:28 ms
// memory:15.9 MB
// title:数组中数字出现的次数 LCOF
// translatedTitle:数组中数字出现的次数
// questionId:100320
// time:2022-10-16 21:57:37

class Solution {
  public:
    vector<int> singleNumbers(vector<int> &nums) {
        int x = 0;
        for (int i : nums)
            x ^= i;
        int B = 0;
        for (int i = 31; i >= 0; i--) {
            if ((x >> i) & 1) {
                B = i;
                break;
            }
        }
        vector<int> V(2);
        for (int i : nums) {
            V[(i >> B) & 1] ^= i;
        }
        return V;
    }
};