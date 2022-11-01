// id:374158892
// runtime:12 ms
// memory:14.9 MB
// title:合并区间
// translatedTitle:合并区间
// questionId:1000338
// time:2022-10-18 15:01:09

const int INF=1e9;
class Solution {
  public:
    bool join(int x1,int y1,int x2,int y2){
        if(x2>y1||y2<x1)return 0;
        return 1;
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        set<pair<int, int>> st;
        for (auto &i : intervals) {
            int l = i[0];
            int r = i[1];
            while(1){
                bool ok=0;
                auto pos = st.lower_bound({r, INF});
                if (pos != st.begin()) {
                    pos--;
                    auto [l2, r2] = *pos;
                    if (join(l,r,l2,r2)) {
                        ok=1;
                        st.erase(pos);
                        l = min(l, l2);
                        r = max(r, r2);
                    }
                }
                if(!ok)break;
            }
            while(1){
                bool ok=0;
                auto pos = st.lower_bound({l, INF});
                if (pos != st.begin()) {
                    pos--;
                    auto [l2, r2] = *pos;
                    if (join(l,r,l2,r2)) {
                        ok=1;
                        st.erase(pos);
                        l = min(l, l2);
                        r = max(r, r2);
                    }
                }
                if(!ok)break;
            }
            st.insert({l, r});
        }
        vector<vector<int>> ret;
        for(auto[a,b]:st)ret.push_back({a,b});
        return ret;
    }
};