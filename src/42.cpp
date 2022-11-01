// id:326023545
// runtime:16 ms
// memory:19.8 MB
// title:Trapping Rain Water
// translatedTitle:接雨水
// questionId:42
// time:2022-06-16 21:05:34

class Solution {
public:
    int trap(vector<int>& V) {
        deque<pair<int,int>>q;
        int ans=0;
        for(int i=0;i<(int)V.size();i++){
            int last=-1;
            while(!q.empty()&&q.back().first<V[i]){
                if(q.size()>=2){
                    auto [a1,b1]=q[q.size()-2];
                    auto [a2,b2]=q[q.size()-1];
                    ans+=(min(a1,V[i])-a2)*(i-b2);
                }
                last=q.back().second;
                q.pop_back();
            }
            if(!q.empty()&&q.back().first==V[i])continue;
            if(last==-1)
                q.push_back({V[i],i});
            else
                q.push_back({V[i],last});
        }
        return ans;
    }
};
