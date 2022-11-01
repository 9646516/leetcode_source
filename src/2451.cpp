// id:377612976
// runtime:4 ms
// memory:7.6 MB
// title:Odd String Difference
// translatedTitle:差值数组不同的字符串
// questionId:2547
// time:2022-10-29 22:33:04

class Solution {
  public:
    string oddString(vector<string> &words) {
        vector<vector<int>> V;
        for (auto &i : words) {
            vector<int> now;
            for (int j = 1; j < i.size(); j++) {
                now.push_back(i[j] - i[j - 1]);
            }
            V.emplace_back(move(now));
        }
        {
            vector<int> bad;
            for (int i = 1; i < V.size(); i++) {
                if (V[i] == V[0]) {
                    continue;
                } else {
                    bad.push_back(i);
                }
            }
            if (bad.size() == 1) {
                return words[bad[0]];
            }
        }
        {
            vector<int> bad;
            for (int i = 0; i < V.size(); i++) {
                if (V[i] == V[1]) {
                    continue;
                } else {
                    bad.push_back(i);
                }
            }
            if (bad.size() == 1) {
                return words[bad[0]];
            }
        }
        return "";
    }
};