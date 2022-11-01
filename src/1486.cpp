// id:80704566
// runtime:0 ms
// memory:5.8 MB
// title:XOR Operation in an Array
// translatedTitle:数组异或操作
// questionId:1610
// time:2020-06-21 10:31:10

class Solution {
  public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans ^= start + 2 * i;
        }
        return ans;
    }
};