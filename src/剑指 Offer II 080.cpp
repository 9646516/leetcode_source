// id:374186624
// runtime:20 ms
// memory:9.8 MB
// title:含有 k 个元素的组合
// translatedTitle:含有 k 个元素的组合
// questionId:1000344
// time:2022-10-18 16:02:28

class Solution {
public:
    vector<vector<int>> ans;
    vector<int>now;
    void dfs(int n,int k){
        if(n==0){
            ans.push_back(now);
        }else{
            int S=now.empty()?1:now.back()+1;
            for(int i=S;i<=k;i++){
                now.push_back(i);
                dfs(n-1,k);
                now.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(k,n);
        return ans;
    }
};