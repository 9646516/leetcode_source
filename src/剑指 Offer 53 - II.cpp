// id:373631393
// runtime:4 ms
// memory:16.6 MB
// title:缺失的数字  LCOF
// translatedTitle:0～n-1中缺失的数字
// questionId:100331
// time:2022-10-16 21:34:12

class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        bitset<10005> st;
        st.set();
        for (int i : nums)
            st[i] = 0;
        return st._Find_first();
    }
};