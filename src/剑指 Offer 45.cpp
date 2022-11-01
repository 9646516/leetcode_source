// id:373610452
// runtime:4 ms
// memory:11.2 MB
// title:把数组排成最小的数 LCOF
// translatedTitle:把数组排成最小的数
// questionId:100323
// time:2022-10-16 20:30:38

class Solution {
  public:
    string minNumber(vector<int> &nums) {
        vector<string> V;
        for (int i : nums) {
            V.emplace_back(to_string(i));
        }
        sort(V.begin(), V.end(), [&](const string &a, const string &b) { return a + b < b + a; });
        string ret;
        for (auto &j : V)
            ret.append(j);
        return ret;
    }
};