// id:374193241
// runtime:12 ms
// memory:10.4 MB
// title:含有重复元素集合的组合
// translatedTitle:含有重复元素集合的组合
// questionId:1000232
// time:2022-10-18 16:18:55

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>now;
    vector<int>V;
    void dfs(int pos,int xs){
        if(xs==0){
            ans.push_back(now);
        }else if(pos<V.size()){
            if(xs-V[pos]>=0){
                now.push_back(V[pos]);
                dfs(pos+1,xs-V[pos]);
                now.pop_back();
            }
            for(int i=pos+1;i<V.size();i++){
                if(V[i]!=V[pos]){
                    dfs(i,xs);
                    break;
                }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        V=candidates;
        sort(V.begin(),V.end());
        dfs(0,target);
        // sort(ans.begin(),ans.end());
        // ans.resize(unique(ans.begin(),ans.end())-ans.begin());
        return ans;
    }
};