// id:373902864
// runtime:116 ms
// memory:86 MB
// title:每日温度
// translatedTitle:每日温度
// questionId:1000282
// time:2022-10-17 19:05:21

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>next(temperatures.size(),0);
        vector<pair<int,int>>V;
        for(int i=0;i<temperatures.size();i++){
            while(!V.empty()&&V.back().second<temperatures[i]){
                next[V.back().first]=i-V.back().first;
                V.pop_back();
            }
            V.push_back({i,temperatures[i]});
        }
        return next;
    }
};