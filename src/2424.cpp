// id:369076072
// runtime:416 ms
// memory:172.4 MB
// title:Longest Uploaded Prefix
// translatedTitle:最长上传前缀
// questionId:2512
// time:2022-10-01 22:34:40

class LUPrefix {
  public:
    int need;
    set<int> st;
    LUPrefix(int n) { need = 1; }

    void upload(int video) {
        st.insert(video);
        while (!st.empty()) {
            if (*st.begin() == need) {
                need++;
                st.erase(st.begin());
            } else {
                break;
            }
        }
    }

    int longest() { return need - 1; }
};