// id:374191120
// runtime:4 ms
// memory:16.2 MB
// title:允许重复选择元素的组合
// translatedTitle:允许重复选择元素的组合
// questionId:1000229
// time:2022-10-18 16:13:45

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>now;
    vector<int>V;
    void dfs(int pos,int xs){
        if(xs==0){
            ans.push_back(now);
        }else if(pos<V.size()){
            dfs(pos+1,xs);
            if(xs-V[pos]>=0){
                xs-=V[pos];
                now.push_back(V[pos]);
                dfs(pos,xs);
                now.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        V=candidates;
        sort(V.begin(),V.end());
        reverse(V.begin(),V.end());
        dfs(0,target);
        return ans;
    }
};