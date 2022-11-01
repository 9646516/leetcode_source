// id:374914068
// runtime:200 ms
// memory:65 MB
// title:Circus Tower LCCI
// translatedTitle:马戏团人塔
// questionId:1000036
// time:2022-10-20 19:29:34

class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        const int N=height.size();
        map<int,vector<int>>mp;
        for(int i=0;i<N;i++){
            mp[height[i]].push_back(weight[i]);
        }
        vector<int>V;
        for(auto &[a,b]:mp){
            sort(b.begin(),b.end(),greater<int>());
            for(int c:b){
                auto pos=lower_bound(V.begin(),V.end(),c);
                if(pos==V.end())V.push_back(c);
                else *pos=c;
            }
        }
        return V.size();
    }
};