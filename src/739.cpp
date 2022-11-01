// id:326160213
// runtime:128 ms
// memory:83.1 MB
// title:Daily Temperatures
// translatedTitle:每日温度
// questionId:739
// time:2022-06-17 10:15:10

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& V) {
        vector<int>ret(V.size());
        deque<int>q;
        for(int i=V.size()-1;i>=0;i--){
            while(!q.empty()&&V[q.back()]<=V[i])q.pop_back();
            if(q.empty())ret[i]=0;
            else{
                ret[i]=q.back()-i;
            }
            q.push_back(i);
        }
        return ret;
    }
};