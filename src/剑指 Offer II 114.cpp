// id:374281575
// runtime:4 ms
// memory:8.7 MB
// title:外星文字典
// translatedTitle:外星文字典
// questionId:1000312
// time:2022-10-18 20:43:31

vector<int>V[255];
int deg[255];
class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<char>sb;
        for(auto&i:words)for(auto j:i)sb.push_back(j);
        sort(sb.begin(),sb.end());
        sb.resize(unique(sb.begin(),sb.end())-sb.begin());
        for(int i:sb){
            V[i].clear();
            deg[i]=0;
        }
        for(int i=1;i<words.size();i++){
            const auto&a=words[i-1];
            const auto&b=words[i];
            const int sz=min(a.size(),b.size());
            int j=0;
            for(;j<sz;j++){
                if(a[j]!=b[j])break;
            }
            if(j!=sz){
                int u=a[j];
                int v=b[j];
                V[u].push_back(v);
                deg[v]++;
            }else{
                if(a.size()<=b.size())continue;
                else {
                    return "";
                }
            }
        }

        queue<int>q;
        for(int i:sb){
            if(!deg[i])q.push(i);
        }
        string ret;
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
        if(ret.size()!=sb.size())ret.clear();
        return ret;
    }
};