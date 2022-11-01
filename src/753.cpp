// id:376335767
// runtime:12 ms
// memory:8.9 MB
// title:Cracking the Safe
// translatedTitle:破解保险箱
// questionId:754
// time:2022-10-25 16:11:41

class Solution {
public:
    vector<string>V;
    string now;
    vector<int>G[5000];
    void dfs(int n,int k){
        if(n==0){
            V.push_back(now);
        }else{
            for(int i=0;i<k;i++){
                now.push_back('0'+i);
                dfs(n-1,k);
                now.pop_back();
            }
        }
    }
    vector<int> res;
    void dfs2(int x) {
        while (!G[x].empty()) {
            int to = G[x].back();
            G[x].pop_back();
            dfs2(to);
        }
        res.push_back(x);
    }

    string crackSafe(int n, int k) {
        if(n==1){
            string ret;
            for(int i=0;i<k;i++)ret.push_back('0'+i);
            return ret;
        }else{
            dfs(n-1,k);
            sort(V.begin(),V.end());
            const int sz=V.size();
            vector<int>deg(5000);
            for(int i=0;i<sz;i++){
                const auto now=V[i];
                for(int j=0;j<k;j++){
                    auto next=now.substr(1);
                    next.push_back('0'+j);
                    int idx=lower_bound(V.begin(),V.end(),next)-V.begin();
                    G[i].push_back(idx);
                    deg[i]++;
                    deg[idx]--;
                }
            }
            int s=0;
            for(int i=0;i<sz;i++){
                if(deg[i]==1){
                    s=i;
                    break;
                }
            }
            dfs2(s);
            // cout<<res.size()<<endl;//k^n
            reverse(res.begin(),res.end());
            string ans=V[res[0]];
            for(int i=1;i<res.size();i++){
                ans.push_back(V[res[i]].back());
            }
            return ans;
        }
    }
};