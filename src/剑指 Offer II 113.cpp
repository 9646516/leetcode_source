// id:374277808
// runtime:20 ms
// memory:12.9 MB
// title:课程顺序
// translatedTitle:课程顺序
// questionId:1000310
// time:2022-10-18 20:34:12

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>V[2005];
        vector<int>deg(numCourses);
        for(auto&i:prerequisites){
            int a=i[0];
            int b=i[1];
            V[b].push_back(a);
            deg[a]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(!deg[i])q.push(i);
        }
        vector<int>ret;
        while(!q.empty()){
            int now=q.front();
            q.pop();
            ret.push_back(now);
            for(int i:V[now]){
                deg[i]--;
                if(deg[i]==0){
                    q.push(i);
                }
            }
        }
        if(ret.size()!=numCourses)ret.clear();
        return ret;
    }
};