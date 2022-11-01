// id:361532554
// runtime:76 ms
// memory:37.8 MB
// title:Most Frequent Even Element
// translatedTitle:出现最频繁的偶数元素
// questionId:2486
// time:2022-09-11 10:50:59

class Solution {
  public:
    int mostFrequentEven(vector<int> &nums) {
        map<int, int> mp;
        for (int i : nums)
            if (i % 2 == 0)
                mp[i]++;
        int ans = -1;
        for (auto [a, b] : mp) {
            if (ans==-1||b > mp[ans])
                ans = a;
        }
        return ans;
    }
};