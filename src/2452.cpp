// id:377618106
// runtime:544 ms
// memory:115.6 MB
// title:Words Within Two Edits of Dictionary
// translatedTitle:距离字典两次编辑以内的单词
// questionId:2550
// time:2022-10-29 22:45:16

class Solution {
  public:
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary) {
        uint64_t H[105];
        uint64_t POW[105];
        POW[0] = 1;
        for (int i = 1; i <= 100; i++)
            POW[i] = POW[i - 1] * 233;
        const int N = queries.front().size();
        unordered_set<uint64_t> st;
        for (auto &i : dictionary) {
            H[0] = i[0];
            for (int j = 1; j < N; j++) {
                H[j] = H[j - 1] * 233 + i[j];
            }
            st.insert(H[N - 1]);
            for (int j = 0; j < N; j++) {
                for (int k = 'a'; k <= 'z'; k++) {
                    uint64_t val = H[N - 1];
                    val -= i[j] * POW[N - 1 - j];
                    val += k * POW[N - 1 - j];
                    st.insert(val);
                }
            }
        }
        vector<string> ret;
        auto test = [&](const string &i) -> bool {
            H[0] = i[0];
            for (int j = 1; j < N; j++) {
                H[j] = H[j - 1] * 233 + i[j];
            }
            if (st.count(H[N - 1]))
                return 1;
            for (int j = 0; j < N; j++) {
                for (int k = 'a'; k <= 'z'; k++) {
                    uint64_t val = H[N - 1];
                    val -= i[j] * POW[N - 1 - j];
                    val += k * POW[N - 1 - j];
                    if (st.count(val))
                        return 1;
                }
            }
            return 0;
        };
        for (auto &i : queries) {
            if (test(i)) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};