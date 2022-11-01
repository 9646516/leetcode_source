// id:373969926
// runtime:8 ms
// memory:9.9 MB
// title:和最小的 k 个数对
// translatedTitle:和最小的 k 个数对
// questionId:1000326
// time:2022-10-17 21:51:55

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        multiset<tuple<int,int,int>>st;
        st.insert({nums1[0]+nums2[0],0,0});
        set<int>vis[1005];
        vector<vector<int>>ret;
        for(int i=0;i<k&&!st.empty();i++){
            auto [_,a,b]=*st.begin();
            ret.push_back({nums1[a],nums2[b]});
            st.erase(st.begin());
            if(a+1<nums1.size()&&!vis[a+1].count(b)){
                vis[a+1].insert(b);
                st.insert({nums1[a+1]+nums2[b],a+1,b});
            }
            if(b+1<nums2.size()&&!vis[a].count(b+1)){
                vis[a].insert(b+1);
                st.insert({nums1[a]+nums2[b+1],a,b+1});
            }
        }
        return ret;
    }
};